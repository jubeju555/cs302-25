#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool dfs(unordered_map<string, vector<string>> &graph, string start, string end, unordered_set<string> &visited)
{
  if (start == end)return true;
  if (visited.find(start) != visited.end())return false;
  visited.insert(start);
  for (string &node : graph[start])
  {
    if (dfs(graph, node, end, visited))return true;
    // cout << "Visiting " << node << endl;
  }
  return false;
}

int fulkerson(){
    
}


int main(){

}