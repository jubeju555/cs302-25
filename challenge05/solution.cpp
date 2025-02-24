// challenge 05
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the vertex with the minimum key value
int minkey(vector<int> key, vector<bool> mstSet, int V)
{
  int min = INT_MAX, min_index = -1;
  for (int v = 0; v < V; v++)
    if (!mstSet[v] && key[v] < min)
    {
      min = key[v];
      min_index = v;
    }
  return min_index;
}

// Main Execution
int primMST(vector<vector<int>> graph, int V)
{
  // stores constructed MST
  vector<int> parent(V);
  // used to pick minimum weight edge
  vector<int> key(V, INT_MAX);
  // represents all vertices in MST
  vector<bool> mstSet(V, false);

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
  int mstwt = 0;
  for (int i = 1; i < V; i++)
  {
    mstwt += graph[i][parent[i]];
  }
  return mstwt;
}

void printMST(vector<vector<int>> graph, int V)
{
  int mst_wt = primMST(graph, V);
  cout << mst_wt << endl;
}

int main(int argc, char *argv[])
{
  int V;
  
  vector<vector<int>> graph;
  while (cin >> V)
  {
    graph.clear();
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
    printMST(graph, V);
  } 

  return 0;
}
