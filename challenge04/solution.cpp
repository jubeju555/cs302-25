// Challenge 04: Graph Paths
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
  }
  return false;
}

int main()
{
  int testnum = 0;
  unordered_map<string, vector<string>> graph;
  unordered_set<string> visited;

  // NEDGES pairs of nodes where the first string is the source and the second string is the destination
  while (true)
  {
    int nedges = 0;
    if (!(cin >> nedges))
    {
      break;
    }

    for (size_t i = 0; i < nedges; i++)
    {
      string start, end;
      cin >> start >> end;
      graph[start].push_back(end);
    }
    // NPATHS which is the number of paths or routes to search for
    int npaths = 0;
    cin >> npaths;
    testnum++;
    for (size_t i = 0; i < npaths; i++)
    {
      string src, dst;
      cin >> src >> dst;

      if (graph.find(src) != graph.end() && dfs(graph, src, dst, visited))
      {
        cout << "In Graph " << testnum << " there is a path from " << src << " to " << dst;
      }
      else
      {
        cout << "In Graph " << testnum << " there is no path from " << src << " to " << dst;
      }
      cout << endl;
      // fix for seg faul, was causing infinite loop 
      visited.clear();
    }
  }
  return 0;
}