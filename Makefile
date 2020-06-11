CC = g++ 
CFLAGS = -Wall -g
DEBUG = -DDEBUG -g  #-D means to define a macro name                            
COVERAGE = --coverage


all: readGraph_TEST shortestPath_TEST matrixDijkstra BinaryHeap_TEST bellmanFord



readGraph_TEST: readGraph_TEST.cpp readGraph.hpp readGraph.cpp
	$(CC) $(CFLAGS) -o readGraph_TEST readGraph_TEST.cpp readGraph.cpp 

shortestPath_TEST: shortestPath_TEST.cpp shortestPath.hpp shortestPath.cpp readGraph.hpp readGraph.cpp BinaryHeap.cpp BinaryHeap.hpp
	$(CC) $(CFLAGS) -o shortestPath_TEST shortestPath_TEST.cpp readGraph.cpp shortestPath.cpp BinaryHeap.cpp

matrixDijkstra: matrixDijkstra.cpp shortestPath.hpp shortestPath.cpp readGraph.hpp readGraph.cpp BinaryHeap.cpp BinaryHeap.hpp
	$(CC) $(CFLAGS) -o matrixDijkstra matrixDijkstra.cpp readGraph.cpp shortestPath.cpp BinaryHeap.cpp 


BinaryHeap_TEST: BinaryHeap_TEST.cpp BinaryHeap.hpp BinaryHeap.cpp
	$(CC) $(CFLAGS) -o BinaryHeap_TEST BinaryHeap_TEST.cpp BinaryHeap.cpp 


listDijkstra: listDijkstra.cpp shortestPath.hpp shortestPath.cpp readGraph.hpp readGraph.cpp BinaryHeap.cpp BinaryHeap.hpp
	$(CC) $(CFLAGS) -o listDijkstra listDijkstra.cpp readGraph.cpp shortestPath.cpp BinaryHeap.cpp 


bellmanFord: bellmanFord.cpp shortestPath.hpp shortestPath.cpp readGraph.hpp readGraph.cpp BinaryHeap.cpp BinaryHeap.hpp
	$(CC) $(CFLAGS) -o bellmanFord bellmanFord.cpp readGraph.cpp shortestPath.cpp BinaryHeap.cpp 

clean: 
		rm readGraph_TEST; rm shortestPath_TEST; rm matrixDijkstra; rm BinaryHeap_TEST; rn listDijkstra; rm bellmanFord;

