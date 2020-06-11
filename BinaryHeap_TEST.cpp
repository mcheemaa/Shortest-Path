#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "BinaryHeap.hpp"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>



using namespace std;


TEST_CASE("TESTING Binary Heap")
{

  
  SECTION("Test Constructor")
  {


  	

  	int numItems = 10;

  	double * priorities = new double [numItems];

  	for (int i = 0; i < numItems; i++) {

  		priorities [i] = i; 

  	}

    BinaryHeap a = BinaryHeap(priorities, numItems);


    for (int i = 0; i < numItems; i++) {

       a.getPriority(i) ;

    }


    REQUIRE (a.getPriority(1) == 1);

	  REQUIRE (a.getItem(0) == 0);

	  REQUIRE (a.getPos(1) == 1);



	  a.decreasePriority(4, 0.5);

	  REQUIRE (a.getPos(1) == 4);


	  REQUIRE (a.getPriority(1) == 1);

	  REQUIRE (a.getItem(0) == 0);


  	REQUIRE (a.contains(0) == true);
	
	  REQUIRE (a.getMin() == 0);

  	a.popMin();

  	REQUIRE (a.getSize() == 9);

  	REQUIRE (a.getMin() == 4);

  	REQUIRE (a.contains(0) == false);
  	
  }

}
