// Word Dice Proj5 - CS302
// Authors: Judah Benjamin, Keaton Wyrick
// Githubs:   Jubeju555       Keatonium
//
// Notice: I'm sorry to the grader, but my formatter refused to reformat things with the pointer right after the type.
//         This made some things look weird but no matter what I do it won't change.
//
// Purpose: The primary purpose of this assignment was to get used to network flow and the algorithms used to
//          solve it. We used BFS and Edmonds-Karp algorithm. Overall the hardest part of the lab was making the
//          graph right.

#include <climits>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

enum NodeType { SOURCE, SINK, DIE, LETTER };

struct Edge;

struct Node {
  int id;
  NodeType type;
  string value;
  vector<Edge *> edges;
  bool visited;
  Edge *backedge;

  Node(int i, NodeType t, string s) {
    id = i;
    type = t;
    value = s;
    visited = false;
    backedge = nullptr;
  }
  Node(int i, NodeType t) {
    id = i;
    type = t;
    value = "";
    visited = false;
    backedge = nullptr;
  }
};

struct Edge {
  Node *from;
  Node *to;
  int capacity;
  int flow;
  Edge *reverse;

  Edge(Node *f, Node *t, int c) {
    from = f;
    to = t;
    capacity = c;
    flow = 0;
    reverse = nullptr;
  }
};

class Graph {
public:
  vector<Node *> nodes;
  Node *source;
  Node *sink;
  vector<int> used_nodes;

  ~Graph();

  void addEdge(Node *from, Node *to, int capacity);
  bool bfs();
  int Karp();
};
//i was running into problems and think it was the way it
//was deleting but i changed like 5 things so idk (this is my coconut.png)
Graph::~Graph() {
  for (Node *node : nodes)
    delete node;
}
//helper function because writing it so many times sucked
void Graph::addEdge(Node *from, Node *to, int capacity) {
  Edge *e1 = new Edge(from, to, capacity);
  Edge *e1r = new Edge(to, from, 0);
  e1->reverse = e1r;
  e1r->reverse = e1;
  from->edges.push_back(e1);
  to->edges.push_back(e1r);
}

bool Graph::bfs() {
  //mark all nodes as not visited (resetting)
  for (Node *n : nodes){
    n->visited = false;
  }
  queue<Node *> cue;
  cue.push(source);
  source->visited = true;

  //while cue is not empty, go through each unvisited node until
  //sink is reached. If sink is not reached, return false.
  while (!cue.empty()) {
    Node *current = cue.front();
    cue.pop();

    for (Edge *e : current->edges) {
      if (!e->to->visited && e->capacity > e->flow) {
        e->to->visited = true;
        e->to->backedge = e;
        cue.push(e->to);
        if (e->to == sink)
          return true;
      }
    }
  }
  return false;
}

//use the Edmonds-Karp algorithm to solve network flow
int Graph::Karp() {
  int flow = 0;
  int path_flow = 0;
  Node *n;
  Edge *e;
  // this is why bfs is a bool :)
  while (bfs()) {
    path_flow = INT_MAX;
    n = sink;
    // start at sink and loop till source. get limiting edge
    while (n != source) {
      e = n->backedge;
      path_flow = min(path_flow, e->capacity - e->flow);
      n = e->from;
    }
    // take it back now ya'll (do it again but update flow)
    n = sink;
    while (n != source) {
      e = n->backedge;
      e->flow += path_flow;
      e->reverse->flow -= path_flow;
      n = e->from;
    }
    flow += path_flow;
  }
  return flow;
}

int main(int argc, char *argv[]) {
  vector<string> dice;
  string word = "";

  ifstream fin(argv[1]);
  string input;
  while (fin >> input)
    dice.push_back(input);

  fin.close();
  fin.open(argv[2]);
  while (fin >> word) {
    Graph g;
    int id = 0;

    g.source = new Node(id++, SOURCE);
    g.sink = new Node(id++, SINK);
    g.nodes.push_back(g.source);

    vector<Node *> die_nodes;
    for (const string &d : dice) {
      Node *die = new Node(id++, DIE, d);
      g.addEdge(g.source, die, 1);
      g.nodes.push_back(die);
      die_nodes.push_back(die);
    }

    vector<Node *> letter_nodes;
    for (char c : word) {
      Node *letter = new Node(id++, LETTER, string(1, c));
      g.addEdge(letter, g.sink, 1);
      g.nodes.push_back(letter);
      letter_nodes.push_back(letter);
    }

    //go through the die values and see if the die match any of the letters
    for (Node *die : die_nodes) {
      for (Node *letter : letter_nodes) {
        //if found (string::npos was found on cppRef)
        if (die->value.find(letter->value) != string::npos) {
          g.addEdge(die, letter, 1);
        }
      }
    }

    g.nodes.push_back(g.sink);
    //if Karp matches word length, find the nodes used and print
    if (g.Karp() == (int)word.length()) {
      for (Node *letter : letter_nodes) {
        for (Edge *e : letter->edges) {
          if (e->to->type == DIE && e->reverse->flow > 0) {
            g.used_nodes.push_back(e->to->id - 2);
            break;
          }
        }
      }
      for (int i = 0; i < (int)(g.used_nodes.size() - 1); i++) {
        cout << g.used_nodes[i] << ",";
      }
      cout << g.used_nodes[g.used_nodes.size() - 1] << ": ";
      cout << word << endl;
      //else print cannot spell
    } else {
      cout << "Cannot spell " << word << endl;
    }
  }
  return 0;
}
