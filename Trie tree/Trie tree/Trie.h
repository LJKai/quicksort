#pragma once
#include <vector>
#include <string>
using namespace std;

class Trie
{private:
	vector<Trie*> dict;
	bool isEnd;
	Trie* searchPrefix(string prefix);
public:
	Trie();
	void insert(string word);
	bool search(string word);
	bool startsWith(string prefix);
};

