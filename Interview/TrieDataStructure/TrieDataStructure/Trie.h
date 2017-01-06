#pragma once
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <memory>
using namespace std;
class Trie
{
	struct TrieNode
	{
		map<char, shared_ptr<TrieNode>> m;
		bool endofWord = false;
	};
	shared_ptr<TrieNode> root = make_shared<TrieNode>();
public:
	Trie() {};

	Trie(const vector<string>& v)
	{
		for (const auto& x : v)
			Insert(x);
	}

	void Insert(const string& str);
	void print(string, const shared_ptr<TrieNode>);
	void PrefixSearch();
	void Test();
	~Trie();
};

