#pragma once
#include <list>
#include <vector>
using namespace std;
class AdjaAdjacencyList
{
	
protected:
	vector<list<int>> al;
	int V;
public:
	explicit AdjaAdjacencyList(int v) : V(v), al(v) {}
	void virtual addEdge(int s, int e) = 0;
	virtual void RemoveEdge(int s, int e) = 0;
	AdjaAdjacencyList();
	virtual ~AdjaAdjacencyList();
};

