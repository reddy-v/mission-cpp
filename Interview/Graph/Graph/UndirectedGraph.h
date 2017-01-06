#pragma once
#include "AdjaAdjacencyList.h"
class UndirectedGraph : public AdjaAdjacencyList
{
	void DFSUtil(int i, vector<bool>& vector);
public:
	UndirectedGraph(int v) : AdjaAdjacencyList(v) { }

	void addEdge(int s, int e) override;
	void RemoveEdge(int s, int e) override;
	void DFS(int);
	~UndirectedGraph();
};

