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

  
  return (0);
}


