// Challenge 04: Graph Paths
// judah benjamin
// feb 11 2025
//  this program reads in graph and tell me whether there is a path between 2 nodes, based on neges and npaths
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Main Execution
bool dfs(unordered_map<string, vector<string>> &graph, string start, string end, unordered_set<string> &visited)
{
  if (start == end)return true;
  if (visited.find(start) != visited.end())return false;
  visited.insert(start);
  for (const string &node : graph[start])
  {
    if (dfs(graph, node, end, visited))return true;
    // cout << "Visiting " << node << endl;
  }
  return false;
}

int main()
{
  int testnum = 0;
  // created bool and forcefully printed out a new line to separate test cases ;)
  bool testcasespace= true;
  // NEDGES pairs of nodes where the first string is the source and the second string is the destination
  while (true)
  {
    int nedges;
    if (!(cin >> nedges))break;
    unordered_map<string, vector<string>> graph;
    for (int i = 0; i < nedges; i++)
    {
      string start, end;
      cin >> start >> end;
      graph[start].push_back(end);
    }
    // NPATHS which is the number of paths or routes to search for
    int npaths;
    if (!(cin >> npaths)) break;
    if (!testcasespace) cout << '\n'; testcasespace = false;
    // cout << "Graph " << testnum << endl;
    testnum++;
    for (int i = 0; i < npaths; i++)
    {
      unordered_set<string> visited;
      string src, dst;
      cin >> src >> dst;   
      cout << "In Graph " << testnum << " there is ";
      if (!(graph.find(src) != graph.end() && dfs(graph, src, dst, visited)))
      {
        cout << "no ";
      }
      else
      {
        cout << "a ";
      }
      cout << "path from " << src << " to " << dst << '\n';


    }

  }
  return 0;
}