////////////////////////////////////////////////////////////////////////////////
// Kar Epker's EECS 281 Project 3
////////////////////////////////////////////////////////////////////////////////

// INCLUDES
// STL
#include <iostream>
// Project
#include "interaction.hpp"
#include "graph.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{

	// get mode
	programmode_t mode;
	try
	{
		mode = parseArgs(argc, argv);
	}
	catch(MessageError me)
	{
		cout << me;
		return 0;
	}

	// construct the Graph
	Graph g;

	// do the calculations
	// find the MST
	if(mode == MST) 
	{
		Tree mst = g.makeMST();
		cout << mst;
	}
	// find a potential suboptimal path using heuristics
	else if(mode == FASTTSP) 	
	{
		Path p = g.fastTSP();
		cout << p;
	}
	// find the optimal TSP using the faster algorithm
	else if(mode == OPTTSP)
	{
		Path p = g.optTSP();
		cout << p;
	}
	// find the optimal TSP using the naive algorithm
	else
	{
		Path p = g.naiveTSP();
		cout << p;
	}

	return 0;
}

