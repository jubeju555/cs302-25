// Challenge 04: Graph Paths
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Main Execution
bool dfs(unordered_map<string, vector<string>> graph, string start, string end, vector<string> visited){
  if (start == end)
  {
    return true;
  }
  visited.push_back(start);
  for (const string &node : graph[start])
  {
  if (find(visited.begin(), visited.end(), node) == visited.end())
  {
    if (dfs(graph, node, end, visited))
    {
      return true;
    }

  }

  return true;
}
int main(int argc, char *argv[]) {
//   ;
//   string line;
//   while (getline(cin, line))
//   {
//     stringstream ss(line);
//     string node;
//     ss >> node;
//     string edge;
//     while (ss >> edge)
//     {
//       graph[node].push_back(edge);
//     }
//     if(graph.find(node) == graph.end())
//     {
//       graph[node] = {};
//     }else
//     {
//       graph[node].push_back("");
//     }
//   }
//   while (cin >> line)
//   {
//     if(graph.find(line) == graph.end())
//     {
//       cout << "In Graph " << line << " there no path from " << node[1] << " to" << endl;
//     }else
//     {
//       cout << "In Graph " << line << " there a " << graph[line].size() << " paths" << endl;
//     }
   

//   }
  
// cout << "graph size: " << graph.size() << endl;
// cout << "graph: " << endl;
// cout << "graph[0]: " << graph["0"].size() << endl;
  
  return (0);
}


