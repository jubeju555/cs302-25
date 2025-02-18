// Challenge 5: Minimum Spanning Tree

// learned what a mspamming tree was from geeksforgeeks
#include <iostream>
#include <vector>
using namespace std;
#include <climits>

// Function to find the vertex with the minimum key value
int minkey(vector<int> key, vector<bool> mstSet, int V)
{
  int min = INT_MAX, min_index;
  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;
  return min_index;
}

// Main Execution
int primMST(vector<vector<int>> graph, int V)
{
  // stors constructed MST
  vector<int> parent;
  // used to pick minimum weight edge
  vector<int> key;
  // represents all vertices in MST
  vector<bool> mstSet(V, false);

  for (int i = 0; i < V; i++)
  {
    key.push_back(INT_MAX);
    parent.push_back(-1);
  }
  key[0] = 0;
  parent[0] = -1;
  for (int i = 0; i < V - 1; i++)
  {
    int u = minkey(key, mstSet, V);
    mstSet[u] = true;

    for (int v = 0; v < V; v++)
    {
      if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
      {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }

  return 0;
}
void printMST(vector<vector<int>> graph, int V)
{
  int mst_wt = primMST(graph, V);
  cout << "Minimum Spanning Tree: " << mst_wt;
}
int main(int argc, char *argv[])
{
  int V;
  vector<vector<int>> graph;
  while (cin >> V)
  {
    for (int i = 0; i < V; i++)
    {
      vector<int> row;
      for (int j = 0; j < V; j++)
      {
        int temp;
        cin >> temp;
        row.push_back(temp);
      }
      graph.push_back(row);
    }
  } 
printMST(graph, V);
  return (0);
}
