/*
judah benjamin 
sb-play
program that plays the game and spits out moves
cs302 march 3rd
  */
#include "disjoint.h"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;
// TO RUN:  sh run_multiple.sh 8 10 5 pbyrg bin/sb-play 100 -
// TO RUN SINGLE TIME: time bin/sb-play 8 10 5 pbyrg <input-1.txt
// TESTING: /home/jplank/cs302/Labs/Lab5/bin/sb-player 8 10 5 pbyrg bin/sb-play y y -

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

  int getColorValue(char color);
  bool isGoalCell(int r, int c);
  vector<pair<int, int>> getNeighbors(int r, int c);
  string makeSwapMove();
  string makeScoreMove(int r, int c);
};

void usage(const char *s)
{
  fprintf(stderr, "usage: sb-read rows cols min-score-size colors\n");
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
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// anakyze board and update - same as sb-analyze.cpp (copy and pasted)
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
      if (scoringset.find(root) == scoringset.end())
      {
        scoringset[root] = {1, s->goals[currentindex] != 0, s->goals[currentindex] ? currentindex : -1};
      }

      if (j + 1 < s->column && s->board[currentindex] == s->board[currentindex + 1])
      {
        ds.Union(ds.Find(currentindex), ds.Find(currentindex + 1));
      }
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

// best move on board
void bestmove(Superball *s, DisjointSetByRankWPC &ds, unordered_map<int, Metadata> &scoringset)
{
  // First check for immediately scorable sets that meet minimum size
  int bestscore = 0;
  int bestscorecell = -1;

  unordered_map<int, Metadata>::iterator it;
  for (it = scoringset.begin(); it != scoringset.end(); ++it)
  {
    // Only consider sets that are big enough and have a goal cell
    if (it->second.has_goal && it->second.size >= s->mss)
    {
      int potentialScore = it->second.size * s->goals[it->second.scorecell];
      if (potentialScore > bestscore)
      {
        bestscore = potentialScore;
        bestscorecell = it->second.scorecell;
      }
    }
  }

  // If  found a valid scoring move, score it
  if (bestscore > s->mss && bestscorecell != -1)
  {
    int scoreRow = bestscorecell / s->column;
    int scoreCol = bestscorecell % s->column;

    cout << "SCORE " << scoreRow << " " << scoreCol << endl;
    return;
  }

  // If no immediate scoring, look for best swap
  int swapI = -1, swapJ = -1;
  int swapX = -1, swapY = -1;
  int bestSwapScore = -1;

  vector<pair<int, int>> cells;
  for (int i = 0; i < s->row; i++)
  {
    for (int j = 0; j < s->column; j++)
    {
      int index = i * s->column + j;
      if (s->board[index] != '.' && s->board[index] != '*')
      {
        cells.push_back(make_pair(i, j));
      }
    }
  }

  // Try all possible swaps
  for (size_t c1 = 0; c1 < cells.size(); c1++)
  {
    for (size_t c2 = c1 + 1; c2 < cells.size(); c2++)
    {
      int i1 = cells[c1].first;
      int j1 = cells[c1].second;
      int idx1 = i1 * s->column + j1;

      int i2 = cells[c2].first;
      int j2 = cells[c2].second;
      int idx2 = i2 * s->column + j2;

      // Skip if same color (no point swapping same colors)
      if (s->board[idx1] == s->board[idx2])
      {
        continue;
      }

      // Perform the swap
      swap(s->board[idx1], s->board[idx2]);

      // Analyze resulting board state with a new disjoint set
      DisjointSetByRankWPC new_ds(s->row * s->column);
      unordered_map<int, Metadata> scoreset;
      unordered_map<int, int> scoringcell;
      sbanalyze(s, new_ds, scoreset, scoringcell);

      // Evaluate this position
      int swapval = 0;

      unordered_map<int, Metadata>::iterator it2;
      for (it2 = scoreset.begin(); it2 != scoreset.end(); ++it2)
      {
        if (it2->second.has_goal && it2->second.size >= s->mss)
        {
          // Prioritize sets that can be scored immediately
          swapval += it2->second.size * 1000;
        }
        else if (it2->second.size >= s->mss / 2)
        {
          // Also give value to growing sets that might become scorable later
          swapval += it2->second.size * 10;
        }
      }

      // If this swap is better, save it
      if (swapval > bestSwapScore)
      {
        bestSwapScore = swapval;
        swapI = i1;
        swapJ = j1;
        swapX = i2;
        swapY = j2;
      }

      // swap back
      swap(s->board[idx1], s->board[idx2]);
    }
  }

  if (swapI != -1)
  {
    cout << "SWAP " << swapI << " " << swapJ << " " << swapX << " " << swapY << endl;
  }
}
// for testing 
void printBoard(Superball *s)
{
  for (int i = 0; i < s->row; i++)
  {
    for (int j = 0; j < s->column; j++)
    {
      char cell = s->board[i * s->column + j];
      if (s->goals[i * s->column + j])
      {
        cell = toupper(cell);
      }
      cout << cell << " ";
    }
    cout << endl;
  }
}

int main(int argc, char **argv)
{
  Superball *s;
  s = new Superball(argc, argv);
  DisjointSetByRankWPC ds(s->row * s->column);
  unordered_map<int, Metadata> scoringset;
  unordered_map<int, int> scoringcell;
  for (int i = 0; i < 100; i++)
  {
    sbanalyze(s, ds, scoringset, scoringcell);
    bestmove(s, ds, scoringset);
  }

  return 0;
}
