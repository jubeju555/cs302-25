// Challenge 04: Graph Paths
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Main Execution

int main(int argc, char *argv[]) {
  unordered_map<string, vector<string>> graph;
  string line;
  while (getline(cin, line))
  {
    stringstream ss(line);
    string node;
    ss >> node;
    string edge;
    while (ss >> edge)
    {
      graph[node].push_back(edge);
    }
    if(graph.find(node) == graph.end())
    {
      graph[node] = {};
    }else
    {
      graph[node].push_back("");
    }
  }
  while (cin >> line)
  {
    if(graph.find(line) == graph.end())
    {
      cout << "In Graph " << line << " there no path from " << node[1] << " to" << endl;
    }else
    {
      cout << "In Graph " << line << " there a " << graph[line].size() << " paths" << endl;
    }
   

  }
  
cout << "graph size: " << graph.size() << endl;
cout << "graph: " << endl;
cout << "graph[0]: " << graph["0"].size() << endl;
  
  return (0);
}


