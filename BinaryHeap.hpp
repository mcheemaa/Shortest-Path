#ifndef BINARYHEAP
#define BINARYHEAP

//An abstract class representing a process
class BinaryHeap
{

	protected:

    double * weights;

    int numItems;

  	int * heap;
  	int size;
  	int * position;
  	
  	int leftC(int pos);
  	int rightC(int pos);
    void heapS (int pos);
  	void minH (int pos);


  	public:


   
  
   
   BinaryHeap(const double* priorities, int numItems);
   ~BinaryHeap();
   int getMin() const;
   void popMin();
   bool contains(int item) const;
   double getPriority(int item) const;
   void decreasePriority(int item, double newPriority); 
   int getSize() const;
   int getItem(int pos) const;
   int getPos(int item) const;
   







};

#endif
