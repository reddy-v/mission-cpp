#include "stdafx.h"
#include "UndirectedGraph.h"
#include <iostream>
using namespace std;


void UndirectedGraph::addEdge(int s, int e)
{
	al[s].push_back(e);
	al[e].push_back(s);
}

void UndirectedGraph::RemoveEdge(int s, int e)
{
	al[s].remove(e);
	al[e].remove(s);
}

void UndirectedGraph::DFSUtil(int i, vector<bool>& visited)
{
	visited[i] = true;
	cout << i << endl;
	for(const auto&x: al[i])
	{
		if (!visited[x])
			DFSUtil(x, visited);
	}
}

void UndirectedGraph::DFS(int x)
{
	vector<bool> visited(V, false);
	for (int j = x; j < V+x; ++j)
	{
		int i = j < V ? j : (j - V);
		if(!visited[i])
		{
			DFSUtil(i, visited);
		}
	}

}

UndirectedGraph::~UndirectedGraph()
{
}
