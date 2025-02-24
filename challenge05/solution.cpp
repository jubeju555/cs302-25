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
int primMST(vector<vector<int>> &graph, int V, vector<int> &parent)
{
  // stores MST
  // vector<int> parent(V);

  // used to pick minimum weight edge
  vector<int> key(V, INT_MAX);
  // represents all vertices in MST
  vector<bool> mstSet(V, false);

  key[0] = 0;
  parent[0] = -1;

  for (int i = 0; i < V - 1; i++)
  {
    int u = minkey(key, mstSet, V);
    if (u == -1) continue;

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

void printMST(vector<vector<int>> &graph, int V)
{
  vector<int> parent(V);
  int mst_wt = primMST(graph, V, parent);
  printf("%d\n", mst_wt);
  // printf("Edges in MST\n");
  for (int i = 1; i < V; i++)
  {
    if (parent[i] != -1)
    {
      // geeks4geeks use min for first and max for second so the order of the char makes sense 
      char a = 'A' + min(parent[i], i);
      char b = 'A' + max(parent[i], i);
      printf("%c%c\n", a, b);
      if(cout.eof()) cout << endl;
    }
  }
}

int main(int argc, char *argv[])
{
  int V;

  while (cin >> V)
  {

    if (V <= 0) break;
  vector<vector<int>> graph(V, vector<int>(V));
  
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        int temp;
        cin >> temp;
        graph[i][j] = (temp == -1) ? 0 : temp;
      }
    //    graph.clear();
    // graph.resize(V); 
    // graph[i] = row;
    }
      printMST(graph, V);

  }

  return 0;
}
