to compile and run both programs, use make test


N	Avg Elapsed Time (s)	Avg Memory Used (MB)
10	    3.6525	                11326.07
20	    7.5492	                10231.66
50	    3.69233	                8921.29
100 	9.58012	                10910.31
200 	12.86918	            10591.29
500	    9.95938	                11347.13
1000	8.60651	                10345.7


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