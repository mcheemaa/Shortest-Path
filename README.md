# Shortest-Path

Muhammad Ahmed Cheema 

Dijkstra's Algorithm & Bellman Ford Algorithm

In this porject we implemented two different shortest path algortihms. Dijkstra's
Algorithm is a greedy which finds the shortest path from a given source to a point.
We first implemented it using the adjacency matrix and then calculated some distances
using it. We then implemented a matrixDijkstra file which takes in four comman line arguments
and finds the shortest distance between the two. It also prints it to a output text file.
We then printed the adjacency list using the readGraph function and tested it in the 
test file for readGraph. We also implemented a minimum binary heap which held the property 
that any child was smaller than the parent, and the root was always the minimum which made it 
easy for us to extract it in a constant time. We also used a position array to keep track of 
the items position which then helped us to check if the item was still contained in the array and 
return true if it was. We then tested the heap to make sure everything was working properly.
The minimum heap was then used to implement the dijstra's algorithm which was then used to 
find shortest distances to all the edges from the source. We then implemented listDijkstra which
used the adjacency list to call the dijkstra function and find the smallest distance. We then used
readGraph to print the edge list and all required materials. This was followed by the implementation
of the Bellman Ford algorithm which falls under the category of Dynamic Programming. We implemented
the Bellman Ford algorithm and used it to find some more shortest paths, and as it works with negative 
weights we used it to find the minimum distance and also to produce the negative cycles which we 
found by calling the getCycle function. We tested all this in the shortestPath_TEST.cpp.

To Test The Program

readGraph_TEST.cpp

  ./readGraph_TEST 

shortestPath_TEST.cpp

  ./shortestPath_TEST
  
matrixDijkstra.cpp
  
  ./matrixDijkstra graph.txt path.txt CandyCastle PeanutBrittleHouse

listDijkstra.cpp

  ./listDijkstra graph.txt listg.txt CandyCastle
  
belmanFord.cpp

  for positive with no negative cycle
  
    ./bellmanFord graph.txt belman.txt CandyCastle 
    
  for negative with a cycle 
  
    ./bellmanFord graph2.txt belman.txt v1 (shows the negative cycle from 1 -> 2 -> 0 -> 3 -> 1)
