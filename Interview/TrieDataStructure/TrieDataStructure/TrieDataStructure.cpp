// TrieDataStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Trie.h"

int main()
{
	vector<string> v{ "abc","acd","bcd","def","a","aba" };
	Trie t(v);
	t.PrefixSearch();
    return 0;
}

