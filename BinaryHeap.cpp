#include "BinaryHeap.hpp"
#include <cstdlib>
#include <iostream>

#include<cmath>

using namespace std;

BinaryHeap:: BinaryHeap(const double* priorities, int numItems)
{
	weights = new double[numItems];

	this->numItems = numItems;

	size = numItems;

	position = new int [numItems];

	heap = new int [numItems];

	

	for (int i = 0; i < numItems; i++) {

		heap [i] = i;
		weights[i] = priorities[i];
		position [i] = i;

	}


	for (int i = floor((numItems-1)/2); i >= 0 ; i--) {

		minH(i);

	}

	/**for (int i = 0; i < numItems; i++) {

		cout << " Heap [" << i << "] " << heap[i]  << endl;

	}

	cout << "\n" << endl;

	for (int i = 0; i < numItems; i++) {

		cout << " Posi [" << i << "] " << position[i] <<  endl;

	}**/
}


int BinaryHeap:: leftC(int pos)
{
	return (2 * pos) + 1; 
}

int BinaryHeap:: rightC(int pos)
{
	return (2 * pos) + 2; 
	
}



void BinaryHeap:: minH(int pos) 
{

	int min = pos;

	if (leftC(pos) < numItems && weights[heap[leftC(pos)]] < weights[heap[min]]) {

		min = leftC(pos);

	}

	if (rightC(pos) < numItems && weights[heap[rightC(pos)]] < weights[heap[min]]) {

		min = rightC(pos);

	}

	if (min != pos) {

		int temp = heap[pos];
		int copy = heap[min];
		
		heap[pos] = copy;
		position[copy] = pos;
		
		heap[min] = temp;
		position[temp] = min;
		minH(min);

	}


}




BinaryHeap:: ~BinaryHeap() 
{

	delete [] heap;
	delete [] weights;
	delete [] position;


}

int BinaryHeap:: getMin() const
{

	return heap [0];

}

void BinaryHeap:: popMin() 
{	

	if (numItems >= 1) {

		// position vector 
		position [heap[0]] = -1;
		heap[0] = heap[numItems-1];
		size --;
		minH(0);

	}
	
}

bool BinaryHeap:: contains(int item) const
{
	if (item < 0 or item >= size) {

		return false;
	}

	else if (position[item] == -1) {

		return false;
	}

	else {

		return true;
	}

}

double BinaryHeap:: getPriority(int item) const
{	

	return weights[item];

}

void BinaryHeap:: decreasePriority(int item, double newPriority) 
{



	if (newPriority >= weights[item] or contains(item) == false) {

		return;

	}

	else {

		weights [item] = newPriority;

		heapS (position[item]);

	}


} 

void BinaryHeap:: heapS (int pos) {

	// set the new position of the item 

	int temp = pos;
	int before = floor((pos-1)/2) ;

	while (temp > 0 and weights[heap[temp]] < weights[heap[before]]) {

		int tempo = heap[temp];
		heap[temp] = heap[before];
		position[heap[before]] = temp;
		heap[before] = tempo;
		position[tempo] = before;
		temp = before;
		before = floor((temp-1)/2) ;

	}


} 

int BinaryHeap:: getSize() const
{

	return size;

}

int BinaryHeap:: getItem(int pos) const
{

	return heap[pos];

}

int BinaryHeap:: getPos(int item) const
{

	return position[item];

}
























