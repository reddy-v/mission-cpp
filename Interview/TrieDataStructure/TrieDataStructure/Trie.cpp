#include "stdafx.h"
#include "Trie.h"


void Trie::Insert(const string& str)
{
	auto temp = root;
	for(const auto& x: str)
	{
		if(temp->m.find(x)!=temp->m.end())
		{
			temp = temp->m[x];
		}
		else
		{
			temp->m[x] = make_shared<TrieNode>();
			temp = temp->m[x];
		}
	}
	if(temp->m.empty())
		temp->endofWord = true;
}

void Trie::print(string s, const shared_ptr<TrieNode> trie_node)
{
	if (trie_node->endofWord == true) {
		cout << s << " ";
		return;
	}
	for(auto& x: trie_node->m)
	{
		print(s+x.first, x.second);
	}
}

void Trie::PrefixSearch()
{
	char ch;
	string str;
	auto temp = root;
	while(cin>>ch)
	{
		str.push_back(ch);
		if (temp->m.find(ch) != temp->m.end())
		{
			cout << "The strings for prefix \""  << str << "\" are :: " << endl;
			print(str, temp->m[ch]);
			temp = temp->m[ch];
		}
		else {
			cout << "Nothing Found" << endl;
			return;
		}
		cout << endl;
	}
}

void Trie::Test()
{
	print("ab", root->m['a']->m['b']);
}

Trie::~Trie()
{
}
