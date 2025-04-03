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
    int mapRows, mapCols;
    // set<int> visited;
    map<string, int> travelcost;
    vector<int> dist;
    vector<vector<int>> adjMatrix;
    int mindist(vector<int> distance, vector<bool> visited);
    int dijkstrasalgo();
    vector<vector<string>> mapgrid; 
    

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
        // holy shit use distance and not dist
        if (!visited[i] && distance[i] <= min) 
        {
            min = distance[i];
            minindex = i;
        }
    }
printf("%d", minindex);
    return minindex;
}

int graph::dijkstrasalgo()
{
    // (distance, vertex) pairs, sorted by distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;

    vector<bool> visited(v, false);
    vector<int> distance(v, INT_MAX);

    int start = 0; 
    distance[start] = 0;

    
    min_pq.push(make_pair(0, start));

    while (!min_pq.empty())
    {
        // Extract the node with the smallest distance
        pair<int, int> topElement = min_pq.top();
        int u = topElement.second;
        min_pq.pop();

    
        if (visited[u]) continue;

        visited[u] = true;

        // Calc row and column of  current node
        int row = u / mapCols;
        int col = u % mapCols;

        vector<pair<int, int>> directions;
        directions.push_back(make_pair(-1, 0));
        directions.push_back(make_pair(1, 0));
        directions.push_back(make_pair(0, -1));
        directions.push_back(make_pair(0, 1));

        for (int i = 0; i < directions.size(); i++)
        {
            int dr = directions[i].first;
            int dc = directions[i].second;
            int newRow = row + dr;
            int newCol = col + dc;

            // Check if the neighbor is within bounds
            if (newRow >= 0 && newRow < mapRows && newCol >= 0 && newCol < mapCols)
            {
                int neighbor = newRow * mapCols + newCol;

                // Calculate the weight dynamically based on the graph representation
                string tileType = mapgrid[newRow][newCol];
                if (travelcost.find(tileType) != travelcost.end())
                {
                    int edgeWeight = travelcost[tileType];
                    if (!visited[neighbor] && distance[u] != INT_MAX && distance[u] + edgeWeight < distance[neighbor])
                    {
                        distance[neighbor] = distance[u] + edgeWeight;

                        // Push the updated distance and node into the priority queue
                        min_pq.push(make_pair(distance[neighbor], neighbor));
                    }
                }
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

    cin >> numpairs;

    //  tile names and their costs
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

    cin >> startRow >> startCol >> endRow >> endCol;

    // Create the graph
    graph g;
    g.v = mapRows * mapCols;
    g.dist.resize(g.v, INT_MAX);

    g.mapgrid = mapgrid;

    
    // Call the Dijkstra's algorithm function
    g.dijkstrasalgo();
    // g.printsolution(g.dist.data(), g.v);

    return 0;
}
