#pragma once
#include "AdjaAdjacencyList.h"
#include <iostream>
using namespace std;
#include <stack>

class DirectedGraph : public AdjaAdjacencyList
{
public:
	void addEdge(int s, int e) override;
	void RemoveEdge(int s, int e) override;
	void BuildOrderUtil(int i, vector<bool>& vector, stack<int>& stack);
	void BuildOrder(int x);
	DirectedGraph(int);
	~DirectedGraph();
};

