#pragma once
#include <memory>
#include <vector>

using namespace std;

class BinaryTree
{
protected :
	struct node
	{
		std::unique_ptr<node> left;
		std::unique_ptr<node> right;
		int data;
		int siz=1;
		node(std::unique_ptr<node> l, std::unique_ptr<node> r, int d) : left(std::move(l)), right(std::move(r)), data(d) { }
	};
	const node* find(int x) const;
	std::unique_ptr<node> root{ nullptr };
public :
	BinaryTree() {}
	void Insert(int);
	explicit BinaryTree(const vector<int>& v);
	void print() const;
	inline const node* getRoot() const { return root.get(); }
	int lengthUtil(const node* node);
	int length();
	bool checkBSTUtil(const node* node, int, int) const;
	bool checkBST();
	int printIndex(int x) const;
private :
	void print(const unique_ptr<node>& n) const;
};
