#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "readGraph.hpp"

#include <fstream>



using namespace std;


TEST_CASE("TESTING readGraph Class")
{

  
  SECTION("Test readGraph")
  {

    ifstream inFile ("graph.txt");
    

    double ** matrix;
    string * vLabels;
    string ** eLabels;
    double ** weights;
    int * lengths;
    int ** adj;
    int ** edgeList;
    int ** numEdges;
    double * wei;
    
    int ** edge;
    int numE;

    string * eL;

    int vert = readGraph(inFile, matrix, vLabels, eLabels);

    REQUIRE(vert == 4);

    cout << "\nAdjacency Matrix \n" << endl;


    for (int i = 0; i < vert; i++) {
      for (int j = 0; j < vert; j++) {

        cout << matrix[i][j] << " " ;
      }
      cout << "\n" <<endl ;
    }

    inFile.clear();
    inFile.seekg(0, ios::beg); // check what this does 

    vert = readGraph(inFile, adj, weights, lengths, vLabels, eLabels);

    REQUIRE(vert == 4);


    cout << "\nEdge Labels \n" << endl;

    
    for (int i = 0; i < vert; i++) {

      cout << "Edge Labels " << "[" << i << "] " ;

      for (int j = 0; j < lengths[i]; j++) {

        cout << eLabels[i][j] << " " ;
      }
      cout << "\n" <<endl ;
    }


    cout << "\nAdjacency List \n" << endl;

    for (int i = 0; i < vert; i++) {

      cout << "Adjacency List " << "[" << i << "] " ;

      for (int j = 0; j < lengths[i]; j++) {

        cout << adj[i][j] << " " ;
      }
      cout << "\n" <<endl ;
    }

    cout << "\nWeights \n" << endl;

    for (int i = 0; i < vert; i++) {

      cout << "Weights " << "[" << i << "] " ;

      for (int j = 0; j < lengths[i]; j++) {

        cout << weights[i][j] << " " ;
      }
      cout << "\n" <<endl ;
    }

    

    cout << "\nVertex Labels  \n" << endl;


    for (int i = 0; i < vert; i++) {

        cout << "[" << i << "] " << vLabels[i] << " " << endl ;
      }
       


    inFile.clear();
    inFile.seekg(0, ios::beg); // check what this does 

    string * vLa;


    vert = readGraph(inFile, edge, wei, numE, vLa, eL);

    REQUIRE(vert == 4);

    cout << "\nEdge List  \n" << endl;


    for (int i = 0; i < numE; i++) {

      cout << "Edge List " << "[" << i << "] " ;

      for (int j = 0; j < 2; j++) {

        cout << edge[i][j] << " " ;
      }

      cout << endl;
    }


    cout << "\nWeights  \n" << endl;

    cout << "Weights: " << "[ " ;


    for (int i = 0; i < numE; i++) {

      cout << wei[i] << " " ;


    }

    cout << "]" << endl;

    cout << "\nNumber Of Edges   \n" << endl;

    cout << "Num Edges: " << numE << endl; ;

    cout << "\nVertex  \n" << endl;

    cout << "Vertex Labels: " << "[ " ;


    for (int i = 0; i < vert; i++) {

      cout << vLa[i] << " " ;


    }
    cout << "]" << endl;



    cout << "\nEdge  \n" << endl;

    cout << "Edge Labels: " << "[ " ;


    for (int i = 0; i < numE; i++) {

      cout << eL[i] << " " ;


    }
    cout << "]\n" << endl;











  }

}