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
    int maprows, mapcols, startrow, startcol, endrow, endcol;
    // set<int> visited;
    map<string, int> travelcost;
    vector<int> dist;
    vector<vector<int>> adjMatrix;
    int mindist(vector<int> distance, vector<bool> visited);
    int dijkstrasalgo();
    vector<vector<string>> mapgrid;
};
void printsolution(vector<int> &dist, vector<int> &parent, int start, int end, int mapcols)
{
    // Print the shortest distance to the goal
    cout << dist[end] << endl;

    // Reconstruct the path
    vector<pair<int, int>> path;
    int v = end;
    while (v != -1)
    {
        int row = v / mapcols;
        int col = v % mapcols;
        path.push_back(make_pair(row, col));
        v = parent[v];
    }

    // Reverse and print the path
    reverse(path.begin(), path.end());
    for (size_t i = 0; i < path.size(); i++)
    {
        cout << path[i].first << " " << path[i].second << endl;
    }
}

int graph::mindist(vector<int> distance, vector<bool> visited)
{

    int min = INT_MAX;
    int minindex = -1;
    int verti = distance.size();
    for (int i = 0; i < verti; i++)
    {
        // holy shit use distand not dist
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;

    vector<bool> visited(v, false);
    dist.assign(v, INT_MAX);

    int start = startrow * mapcols + startcol;
    dist[start] = 0;
    minpq.push(make_pair(0, start));
    
    int end = endrow * mapcols + endcol;
    vector<int> parent(v, -1); 

    while (!minpq.empty())
    {
        // Extract the node with the smallest distance
        pair<int, int> topElement = minpq.top();
        int u = topElement.second;
        minpq.pop();

        if (visited[u]) continue;
        
        visited[u] = true;

        // Calc row and column of current node
        int row = u / mapcols;
        int col = u % mapcols;

        vector<pair<int, int>> directions;
        directions.push_back(make_pair(-1, 0));
        directions.push_back(make_pair(1, 0));
        directions.push_back(make_pair(0, -1));
        directions.push_back(make_pair(0, 1));

        for (int i = 0; i < directions.size(); i++)
        {
            int newrow = row + directions[i].first;
            int newcol = col + directions[i].second;

            // Check if the neighbor is within bounds
            if (newrow >= 0 && newrow < maprows && newcol >= 0 && newcol < mapcols)
            {
                int neighbor = newrow * mapcols + newcol;

                // Calculate the weight  based on the graph 
                string tiletype = mapgrid[newrow][newcol];
                if (travelcost.find(tiletype) != travelcost.end())
                {
                    int edgeWeight = travelcost[tiletype];
                    if (!visited[neighbor] && dist[u] != INT_MAX && dist[u] + edgeWeight < dist[neighbor])
                    {
                        dist[neighbor] = dist[u] + edgeWeight;
                        parent[neighbor] = u;

                        // Push the updated distand node into the priority queue
                        minpq.push(make_pair(dist[neighbor], neighbor));
                    }
                }
            }
        }
    }
    printsolution(dist, parent, start, end, mapcols);
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

int main()
{
    graph g;

    // order of read in
    int numpairs;
    cin >> numpairs;

    //  tile names and their` cost`s
    for (int i = 0; i < numpairs; i++)
    {
        string tileName;
        int tileCost;
        cin >> tileName >> tileCost;
        g.travelcost[tileName] = tileCost;
    }

    cin >> g.maprows >> g.mapcols;

    // Resize the map grid
    g.mapgrid.resize(g.maprows, vector<string>(g.mapcols));
    for (int i = 0; i < g.maprows; i++)
    {
        for (int j = 0; j < g.mapcols; j++)
        {
            cin >> g.mapgrid[i][j];
        }
    }

    cin >> g.startrow >> g.startcol >> g.endrow >> g.endcol;
    // cout << "Start Position: (" << startrow << ", " << startcol << ")" << endl;
    // cout << "End Position: (" << endrow << ", " << endcol << ")" << endl;

    g.v = g.maprows * g.mapcols;
    g.dist.resize(g.v, INT_MAX);

    // Call the Dijkstra's algorithm function
    g.dijkstrasalgo();
    // g.printsolution(g.dist.data(), g.v);

    return 0;
}
