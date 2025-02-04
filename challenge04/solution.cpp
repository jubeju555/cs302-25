// Challenge 04: Graph Paths
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Main Execution
bool dfs(unordered_map<string, vector<string>> graph, string start, string end, vector<string> visited)
{
  if (start == end)
    return true;
  if (visited.begin() != visited.end())
    return false;
  visited.push_back(start);

  for (const string &node : graph[start])
  {
    if (dfs(graph, node, end, visited))
    {
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[])
{
  unordered_map<string, vector<string>> graph;
  // NEDGES pairs of nodes where the first string is the source and the second string is the destination
  int npaths;
  while (true)
  {
    int nedges;
    if (!(cin >> nedges)){
      break;
    }

  
    for (size_t i = 0; i < nedges; i++)
    {
      string start, end;
      cin >> start >> end;
      graph[start].push_back(end);
    }
// NPATHS which is the number of paths or routes to search for
    int npaths;
    cin >> npaths;
    for (size_t i = 0; i < npaths; i++)
    {
      string src,dst;
      cin >> src >> dst;
      graph[src].push_back(dst);
    }
    
    
  }
  // unordered_map<string, vector<string>> graph;
  // vector<string> visited;
  // string start = "A";
  // string end = "B";
  // int graphnum;
  // while (cin >> graphnum >> start >> end)
  // {
  //   if (dfs(graph, start, end, visited) == true)
  //   {
  //     cout << "In Graph " << graphnum << " there is a path from " << start << " to " << end << endl;
  //   }
  //   else if (dfs(graph, start, end, visited) == false)
  //   {
  //     cout << "In Graph " << graphnum << " there is no path from " << start << " to " << end << endl;
  //   }
  // }

  return 0;
}
