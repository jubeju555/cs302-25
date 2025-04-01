// dijkstra's.cpp

// Main Execution

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <queue>
#include <algorithm>
#include <set>
#include <climits>
#include <map>
#include <string>

using namespace std;
// need something to store weights
/*and need something to store graph - lets use a priority queue, since the smallest weight will just be at the top
we can use like a min heap and keep finding the smallest way to a encompass the "map"
*/
// pretty close to geeks4geeks might need to change to queue
struct graph
{
    int weight = 0;
    int node;
    int v;
    // set<int> visited;
    vector<int> dist;
    int mindist(vector<int> distance, vector<bool> visited);
    int dijkstrasalgo();

};
void printsolution(int dist[], int n)
{
    int v = n;
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < v; i++)
        printf("\t%d       %d\n", i, dist[i]);
}
int graph::mindist(vector<int> distance, vector<bool> visited)
{

    int min = INT_MAX;
    int minindex = -1;
    int verti = distance.size();
    for (int i = 0; i < verti; i++)
    {
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            minindex = i;
        }
    }
    printf("%d", minindex);
    return minindex;
}

int graph::dijkstrasalgo()
{
    // Priority queue to store (distance, vertex) pairs, sorted by distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;

    vector<bool> visited(v, false);
    vector<int> distance(v, INT_MAX);

    int start = 0; // Assuming the start node is 0
    distance[start] = 0;

    // Push the start node into the priority queue
    min_pq.push({0, start});

    while (!min_pq.empty())
    {
        // Extract the node with the smallest distance
        int u = min_pq.top().second;
        min_pq.pop();

        // If the node is already visited, skip it
        if (visited[u])
            continue;

        visited[u] = true;

        // Iterate through all neighbors of the current node
        for (int i = 0; i < v; i++)
        {
            // Check if there's an edge and the node is not visited
            if (!visited[i] && distance[u] != INT_MAX && distance[u] + weight < distance[i])
            {
                distance[i] = distance[u] + weight;

                // Push the updated distance and node into the priority queue
                min_pq.push({distance[i], i});
            }
        }
    }

    printsolution(distance.data(), v);
    return 0;
}

/*
- order of read in
amount of pairs
pairs
graph(rows, columns)
start row  start col
target row target col
*/
 


int main(int argc, char *argv[])
{
    // order of read in
    int numpairs;
    map<string, int> travelcost;
    int mapRows, mapCols;
    vector<vector<string>> mapgrid;
    int startRow, startCol, endRow, endCol;

    // Read the number of tile types
    cin >> numpairs;

    // Read tile names and their costs
    for (int i = 0; i < numpairs; i++)
    {
        string tileName;
        int tileCost;
        cin >> tileName >> tileCost;
        travelcost[tileName] = tileCost;
    }

    cin >> mapRows >> mapCols;

    // Read the map grid
    mapgrid.resize(mapRows, vector<string>(mapCols));
    for (int i = 0; i < mapRows; i++)
    {
        for (int j = 0; j < mapCols; j++)
        {
            cin >> mapgrid[i][j];
        }
    }

    // Read the start and end positions
    cin >> startRow >> startCol >> endRow >> endCol;

    // Create the graph
    graph g;
    g.v = mapRows * mapCols;
    g.dist.resize(g.v, INT_MAX);

    // Call the Dijkstra's algorithm function
    g.dijkstrasalgo();

    return 0;
}
