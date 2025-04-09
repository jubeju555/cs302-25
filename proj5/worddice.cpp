#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;
struct graph{
  unordered_map<string, vector<string>> &graph;
   string start;
   string end;
   unordered_set<string> &visited;
   bool bfs();
   int fulkerson();


};
// bool graph::dfs()
// {
//   if (start == end)return true;
//   if (visited.find(start) != visited.end())return false;
//   visited.insert(start);
//   for (string &node : graph[start])
//   {
//     // Save current node as parent of neighbor
//     start = node;
//     if (visited.find(node) == visited.end() && dfs())
//       return true;
//     start = this->start; // Backtrack
//     // cout << "Visiting " << node << endl;
//   }
//   return false;
// }

bool graph::bfs()
{
  // Clear visited set
  visited.clear();
  
  //  queue since its BFS 
  vector<string> queue;
  queue.push_back(start);
  visited.insert(start);
  
  // Keep track of parent nodes for path reconstruction
  unordered_map<string, string> pathtracker;
  
  while (!queue.empty())
  {
    string current = queue.front();
    queue.erase(queue.begin());   
    
    // If we reached the destination
    if (current == end)
      return true;
    
    // Explore all adjacent vertices
    for ( string &neighbor : graph[current])
    {
      // If not visited, mark as visited and enqueue
      if (visited.find(neighbor) == visited.end())
      {
        visited.insert(neighbor);
        pathtracker[neighbor] = current;
        queue.push_back(neighbor);
      }
    }
  }
  
  // No path found
  return false;
}
int graph::fulkerson(){
  int u,v;
  vector<int> parent;
 int maxflow = 0;
 
 while (bfs())
 {
    int pathflow = INT_MAX;
  
    
 }
 
}

int main(){

}