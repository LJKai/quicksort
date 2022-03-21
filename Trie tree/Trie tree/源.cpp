#include <iostream>
#include "Trie.h"
using namespace std;

/*main为测试案例，参考力扣208题*/
int main()
{
	Trie trie;
	trie.insert("apple");
	/*apple单词是否已经存储，存在则返回true,不存在返回false*/
	bool a = trie.search("apple");
	if (a)
	{
		cout << "apple存在" << endl;
	}
	/*app单词是否已经存储，存在则返回true,不存在返回false*/
	bool b = trie.search("app");     // 返回 False
	if (!b)
	{
		cout << "app单词不存在" << endl;
	}
	/*app前缀是否已经存储，存在则返回true,不存在返回false*/
	bool c = trie.startsWith("app"); // 返回 True
	if (c)
	{
		cout << "app前缀存在" << endl;
	}
	return 0;
}
