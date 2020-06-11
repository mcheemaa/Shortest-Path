#include "shortestPath.hpp"
#include "BinaryHeap.hpp"

#include "readGraph.hpp"
#include <fstream>
#include <string>

#include <cstdlib>
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

void dijkstra(const double* const * matrix, int numVertices, int source, double*& dist, int*& prev)
{

	dist = new double [numVertices];
	prev = new int [numVertices];

	for (int i = 0; i < numVertices; i++) {

			dist[i] = numeric_limits<double>::infinity();
			prev [i] = -1;
		
	}

	dist [source] = 0;

	for (int i = 0; i < numVertices; i++) {

		for (int j = 0; j < numVertices; j++) {

			if(!(isinf(matrix[i][j])) && matrix[i][j] != 0) {

				if(dist[i] + matrix[i][j] <= dist[j] ){

					prev[j] = i;
					dist[j] = dist[i] + matrix[i][j];
				}
			}
		}
	}

	for (int i = 0; i < numVertices; i++) {

		for (int j = 0; j < numVertices; j++) {

	
			if(!(isinf(matrix[i][j])) && matrix[i][j] != 0) {


				if(dist[i] + matrix[i][j] <= dist[j] ){

					prev[j] = i;
					dist[j] = dist[i] + matrix[i][j];
					
				}
			}
		}
	}

}

int getPath(int source, int dest, const int* prev, int*& path)
{
	int pointer = dest;
	int size = 1;

	while (pointer != source) {

		pointer = prev[pointer];
		size ++;
	}

	path = new int(size);


	int point = dest;

	int ind = size - 1;

	while (point != source) {
		
		//cout<< ind <<endl;
		path [ind] = point;
		point = prev[point];
		ind --;
	}

	path[0] = source;



	return size;


}



void dijkstra(const int* const * adj, const double* const * weights, const int* lengths, int numVertices, int source, double*& dist, int*& prev)
{

	dist = new double [numVertices];
	prev = new int [numVertices];

	for (int i = 0; i < numVertices; i++) {

			dist[i] = numeric_limits<double>::infinity();
			prev[i] = -1;
		
	}

	dist [source] = 0;

	BinaryHeap newH (dist, numVertices);

	newH.decreasePriority(source, 0.0);

	int min = newH.getMin();

	//cout << "Min " << min << endl;
	newH.popMin();

	dist[min] = 0;

	for (int i = 1; i < numVertices; i++)
	{
		for (int j = 0; j < lengths[min]; j++)
		{
			int mat = adj[min][j];

			if (newH.contains(mat) and dist[min] + weights[min][j] < newH.getPriority(mat)) {

				//out << "Goes Into If" << endl;
				newH.decreasePriority(mat, dist[min] + weights[min][j]);
				prev[mat] = min;
			}
		}

		min = newH.getMin();
		dist[min] = newH.getPriority(min);
		newH.popMin();
	}
}

int bellmanFord(const int* const * edges, const double* weights, int numVertices, int numEdges, int source, double*& dist, int*& prev) 
{

	dist = new double [numVertices];
	prev = new int [numVertices];

	for (int i = 0; i < numVertices; i++) {

			dist[i] = numeric_limits<double>::infinity();
			prev[i] = -1;
		
	}

	dist [source] = 0;

	int cycle = -1;

	for (int i = 0; i < numVertices; i++) {

		for (int j = 0; j < numEdges; j++) {

			if ((dist[edges[j][0]] + weights[j]) < dist[edges[j][1]]) {

				dist[edges[j][1]] = dist[edges[j][0]] + weights[j];
				prev[edges[j][1]] = edges[j][0];

			}
		}
	}

	double * cycleA = new double [numVertices];
	int * cycleP = new int [numVertices];

	for (int i = 0; i < numVertices; i++) {

		cycleA [i] = dist [i];
		cycleP [i] = prev [i];

	}




	for (int j = 0; j < numEdges; j++) {

		if ((dist[edges[j][0]] + weights[j]) < dist[edges[j][1]]) {

			//cout << "Cycle Gets Updated: " << edges[j][1] << endl;

			dist[edges[j][1]] = cycleA[edges[j][0]] + weights[j];
			prev[edges[j][1]] = edges[j][0];

			cycle = edges[j][1];

		}
	}

	return cycle;
}


int getCycle(int vertex, const int* prev, int numVertices, int*& cycle)
{



	bool * visit = new bool [numVertices];

	for (int i = 0; i < numVertices; i++) {

		visit[i] = false;

	}

	int ind = vertex;

	int counter = 0;

	//cout << prev[ind] << endl;

	//bool a = visit[prev[ind]];

	while (counter < numVertices) {

		//cout << "Goes Into While Loop " << endl;

		if (visit[prev[ind]] == false) {

			visit[prev[ind]] = true;
			ind = prev[ind];
			counter ++;

		}

		else {

			ind = prev[ind];
			counter ++;
			break;
		}

	}

	cycle = new int [counter + 1];
	ind = vertex;

	for (int i = counter; i >= 0; i--) {

		cycle[i] = ind;
		ind = prev[ind];
	}

	return counter + 1;


}















