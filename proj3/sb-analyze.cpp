/*
judah benjamin
superball part 1
this program reads in a board, lookes at possible swaps and sets, sotres the meta data and reports it. */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include "disjoint.h"
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Superball
{
public:
  Superball(int argc, char **argv);
  int row;
  int column;
  int mss;
  int empty;
  vector<int> board;
  vector<int> goals;
  vector<int> colors;

private:
  // DisjointSetByRankWPC ds;
  // vector<vector<int> > board;
  int rows, cols;
};

void usage(const char *s)
{
  fprintf(stderr, "usage: sb-analyze rows cols min-score-size colors\n");
  if (s != NULL)
    fprintf(stderr, "%s\n", s);
  exit(1);
}

Superball::Superball(int argc, char **argv)
{
  int i, j;
  string s;

  if (argc != 5)
    usage(NULL);

  if (sscanf(argv[1], "%d", &row) == 0 || row <= 0)
    usage("Bad rows");
  if (sscanf(argv[2], "%d", &column) == 0 || column <= 0)
    usage("Bad cols");
  if (sscanf(argv[3], "%d", &mss) == 0 || mss <= 0)
    usage("Bad min-score-size");

  colors.resize(256, 0);

  for (i = 0; i < (int)strlen(argv[4]); i++)
  {
    if (!isalpha(argv[4][i]))
      usage("Colors must be distinct letters");
    if (!islower(argv[4][i]))
      usage("Colors must be lowercase letters");
    if (colors[argv[4][i]] != 0)
      usage("Duplicate color");
    colors[argv[4][i]] = 2 + i;
    colors[toupper(argv[4][i])] = 2 + i;
  }

  board.resize(row * column);
  goals.resize(row * column, 0);

  empty = 0;

  for (i = 0; i < row; i++)
  {
    if (!(cin >> s))
    {
      fprintf(stderr, "Bad board: not enough rows on standard input\n");
      exit(1);
    }
    if ((int)s.size() != column)
    {
      fprintf(stderr, "Bad board on row %d - wrong number of characters.\n", i);
      exit(1);
    }
    for (j = 0; j < column; j++)
    {
      if (s[j] != '*' && s[j] != '.' && colors[s[j]] == 0)
      {
        fprintf(stderr, "Bad board row %d - bad character %c.\n", i, s[j]);
        exit(1);
      }
      board[i * column + j] = s[j];
      if (board[i * column + j] == '.')
        empty++;
      if (board[i * column + j] == '*')
        empty++;
      if (isupper(board[i * column + j]) || board[i * column + j] == '*')
      {
        goals[i * column + j] = 1;
        board[i * column + j] = tolower(board[i * column + j]);
      }
    }
  }
}

struct Metadata
{
  int size;
  bool has_goal;
  int scorecell;
};
// reads and stores the metadata of the board
void sbanalyze(Superball *s, DisjointSetByRankWPC &ds, unordered_map<int, Metadata> &scoringset, unordered_map<int, int> &scoringcell)
{
  scoringset.clear();
  scoringcell.clear();

  for (int i = 0; i < s->row; i++)
  {
    for (int j = 0; j < s->column; j++)
    {
      int currentindex = i * s->column + j;
      if (s->board[currentindex] == '.' || s->board[currentindex] == '*')
        continue;

      int root = ds.Find(currentindex);
      // index at one
      if (scoringset.find(root) == scoringset.end())
      {
        scoringset[root] = {1, s->goals[currentindex] != 0, s->goals[currentindex] ? currentindex : -1};
      }
      // check right 
      if (j + 1 < s->column && s->board[currentindex] == s->board[currentindex + 1])
      {
        ds.Union(ds.Find(currentindex), ds.Find(currentindex + 1));
      }
      // checks down
      if (i + 1 < s->row && s->board[currentindex] == s->board[currentindex + s->column])
      {
        ds.Union(ds.Find(currentindex), ds.Find(currentindex + s->column));
      }
    }
  }

  for (int i = 0; i < s->row; i++)
  {
    for (int j = 0; j < s->column; j++)
    {
      int currentindex = i * s->column + j;
      if (s->board[currentindex] == '.' || s->board[currentindex] == '*')
        continue;

      int root = ds.Find(currentindex);
      // if the root is in the scoring set
      if (scoringset.find(root) != scoringset.end())
      {
        scoringset[root].size++;
        scoringset[root].has_goal |= (s->goals[currentindex] != 0);
        if (s->goals[currentindex] && (scoringset[root].scorecell == -1 || currentindex < scoringset[root].scorecell))
        {
          scoringset[root].scorecell = currentindex;
        }
      }
    }
  }
}
// prints the scoring sets
void print(Superball *s, unordered_map<int, Metadata> &scoringset)
{
  printf("Scoring sets: \n");
  for (unordered_map<int, Metadata>::iterator it = scoringset.begin(); it != scoringset.end(); it++)
  {
    // double check what these 2 lines are doing
    int root = it->first;
    Metadata data = it->second;
    // quick calculation of row and column, as well as size and color
    if (data.size > s->mss && data.has_goal && data.size > 1 && data.scorecell != -1)
    {
      int Grow = data.scorecell / s->column ;
      int Gcol = data.scorecell % s->column ;
      char scolor = s->board[data.scorecell];
      // cheeky way of setting sizes back to correct 
      if (data.size > 1) printf("  Size: %2d  Char: %c  Scoring Cell: %d,%d\n", data.size - 1, scolor, Grow, Gcol); 
      else printf("  Size: %2d  Char: %c  Scoring Cell: %d,%d\n", data.size, scolor, Grow, Gcol);
    }
  }
}

int main(int argc, char **argv)
{
  Superball *s;
  s = new Superball(argc, argv);
  DisjointSetByRankWPC ds(s->row * s->column);
  unordered_map<int, Metadata> scoringset;
  unordered_map<int, int> scoringcell;
  
  sbanalyze(s, ds, scoringset, scoringcell);
  print(s, scoringset);

  delete s;
  return 0;
}
