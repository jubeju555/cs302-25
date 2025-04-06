to compile and run both programs, use make test

10, 20, 50, 100, 200, 500, 1000
Benchmark your dijkstras path finding component on each of these map sizes and record the elapsed time and memory usage in a Markdown table as demonstrated below:

| N    | Elapsed Time (s) | Memory Used (MB) |
|------|------------------|------------------|
| 10   | 1.68339           | 5994.03            |
| 20   | 9.98461           | 6012.1            |
| 50   | 0.200047           | 3.31172            |
| 100   | 1.73549           | 6021.53            |
| 200   | 16.285           | 12044.5            |
| 500   | 13.3735           | 11814.9            |
| 1000   | 7.6066           | 11600            |
Note: You should run multiple trials (e.g 5) and average the results.

Note: You should choose the top-left and bottom-right corners as the starting and ending points respectively.

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

theoretically, the increase should me greater then linear, as the size increases, i thikng it should be n^2 log n^2, so the time should increase exponentially. 