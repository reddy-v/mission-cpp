/*
 * http://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/
 * Given a stream of characters, find the first non-repeating character from stream. 
 * You need to tell the first non-repeating character in O(1) time at any moment.
 */
#include "stdafx.h"
#include "DList.h"
#include <iostream>
#include <vector>

using namespace std;

class FindFirstNonRepeatingCharacter
{
private :
	DList dl;
public :
	void Solution1()
	{
		vector<noded*> DLL(256, nullptr);
		vector<bool> repeat(256, false);
		cout << repeat.size() << endl;
		cout << boolalpha << repeat[117] << endl;
		char ch;
		while(cin >> ch)
		{
			auto i = static_cast<size_t>(ch);
			if(repeat[i]==true)
			{
				cout << "First Non Repeating Charcter is :: " << dl.HeadData() << endl;
			}
			else
			{
				if(DLL[i]==nullptr)
				{
					DLL[i]=dl.Insert(ch);
					cout << "First Non Repeating Charcter is :: " << dl.HeadData() << endl;
				}
				else
				{
					repeat[i] = true;
					dl.Remove(DLL[i]);
					cout << "First Non Repeating Charcter is :: " << dl.HeadData() << endl;
				}
			}
		}
	}
};

int yyy()
{
	FindFirstNonRepeatingCharacter ffnrc;
	ffnrc.Solution1();
	return 0;
}