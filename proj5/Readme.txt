Contribution Summary: 

Judah: wrote bfs and karp 

Keaton: wrote main, put them together, and did the testing associated with that


Time complexity: karp = O(v * e^2), words = O(nodes * (dice + words^3))

Adjacency List: Used to store each node’s outgoing edges efficiently. Keeps graph memory-light and makes traversal easy.
Queue: Used for BFS to find shortest augmenting paths in Edmonds-Karp. Ensures correct order of node exploration.
Graph: Represents the flow network. Contains methods for adding edges, finding augmenting paths, and calculating maximum flow.
