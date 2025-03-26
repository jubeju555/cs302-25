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
struct graph {
    int weight;
    int node;
    int v;
    set<int> visited;
    vector<int> dist;
    int mindist();
    int dijkstrasalgo();
};

int graph::mindist()
{
    
    int min = INT_MAX, minindex;
    int verti = 0;
    for (int i = 0; i < verti; i++)
    {
        if (visited.find(i) == visited.end() && dist[i] <= min)
        {
            min = dist[i];
            minindex = i;
        }
    }
    printf("%d", minindex);
    return minindex;
}


void printSolution(int dist[], int n)
{
    int v = n;
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < v; i++)
        printf("\t%d \t\t\t\t %d\n", i, dist[i]);
}

int graph::dijkstrasalgo()
{
    int weight = 0;
    int start = 0;
    int end = 0;
    priority_queue<int> minqueue;

    // store shortest path somewhere in an int
    // use a bool to check if the node is the shortest path
    // use mindist function to actually find the shortest path
    // update the distances of the nodes
    // use a priority queue to store the weights
    
    // Initialize distances to all vertices as infinite and distance to the source as 0
    dist.resize(v, INT_MAX);
    dist[start] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < v - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = mindist();
        visited.insert(u);

        // Update dist value of the adjacent vertices of the picked vertex
        for (int i = 0; i < v; i++)
        {   // double check if this is correct
            // Update dist[i] if it is not in visited, there is an edge from u to i,
            // and total weight of path from start to i through u is smaller than current value of dist[i]
            if (!visited.count(i) && dist[u] != INT_MAX && dist[u] + weight < dist[i])
            {
                dist[i] = dist[u] + weight;
            }
        }
    }
    // Print the constructed distance array
    printSolution(dist.data(), v);
}



/*
order of read in
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
    map<string, int> tilecosts;
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
        tilecosts[tileName] = tileCost;
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

    // adjancency list with directions
    vector<pair<int, int>> directions;
    directions.push_back(pair<int, int>(-1, 0));
    directions.push_back(pair<int, int>(1, 0));
    directions.push_back(pair<int, int>(0, -1));
    directions.push_back(pair<int, int>(0, 1));

    

    // Call Dijkstra's algorithm
    g.dijkstrasalgo();

    return 0;
}
