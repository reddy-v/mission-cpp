#include "stdafx.h"
#include "DirectedGraph.h"
#include <stack>


void DirectedGraph::addEdge(int s, int e)
{
	al[s].push_back(e);
}

void DirectedGraph::RemoveEdge(int s, int e)
{
	al[s].remove(e);
}

void DirectedGraph::BuildOrderUtil(int i, vector<bool>& visited, stack<int>& s)
{
	visited[i] = true;
	for(auto& x: al[i])
	{
		if (!visited[x])
			BuildOrderUtil(x, visited, s);
	}
	s.push(i);
}

void DirectedGraph::BuildOrder(int x)
{
	vector<bool> visited(V, false);
	stack<int> s;
	for (int j = x; j < V+x; ++j)
	{
		int i = j < V ? j : (j - V);
		if (!visited[i]) {
			BuildOrderUtil(i, visited, s);
		}
	}
	while(!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}

DirectedGraph::DirectedGraph(int x) : AdjaAdjacencyList(x)
{
}


DirectedGraph::~DirectedGraph()
{
}
