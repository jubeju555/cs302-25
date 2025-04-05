Additional questions
When you are finished implementing your dijkstras implementation answer the following questions in your README.md :

Write a program, generate_map, that given N generates a NxN map of random tiles. Use this program to generate random maps with the following values of N:

10, 20, 50, 100, 200, 500, 1000
Benchmark your dijkstras path finding component on each of these map sizes and record the elapsed time and memory usage in a Markdown table as demonstrated below:

| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | ...           | ...            |
| 20            | ...           | ...            |
| 50            | ...           | ...            |
| 100           | ...           | ...            |
| 200           | ...           | ...            |
| 500           | ...           | ...            |
| 1000          | ...           | ...            |
|---------------|---------------|----------------|
Note: You should run multiple trials (e.g 5) and average the results.

Note: You should choose the top-left and bottom-right corners as the starting and ending points respectively.

In addition to the table above, each member must provide a brief summary of their individual contributions to the project and each member must independently answer the following questions based on the shared table above:

How did you represent the map as a graph?

used a 2d grid, each cell is a tile, tiles connected by edges, then (up, down,left,right) for traversing

Explain which graph representation you used and how you determined the relationship between vertices include the edges and their weights.


What is complexity of your implementation of Dijkstra's Algorithm?
the time complexity is O(v+e log v)

Explain this by describing which data structures you used and how you used them to implement path finding.
used a priority queue, and 2 vectors for distance and the previous node

How well does your implementation scale?
i think that it does scale well, but im not sure how it will scale to huge levels, but it may be better then average. 

Explain what effect did N (ie. the size of the map) have on the performance of your dijkstras path finding component in terms of execution time and memory usage?