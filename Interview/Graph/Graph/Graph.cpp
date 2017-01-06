// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DirectedGraph.h"

int main()
{
	DirectedGraph dg(8);
	dg.addEdge(0, 2);
	dg.addEdge(1, 2);
	dg.addEdge(1, 3);
	dg.addEdge(2, 4);
	dg.addEdge(4, 5);
	dg.addEdge(3, 5);
	dg.addEdge(5, 6);
	dg.addEdge(4, 7);
	dg.BuildOrder(4);

	return 0;
}


