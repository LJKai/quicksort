#include "Trie.h"

Trie* Trie::searchPrefix(string prefix)
{
	Trie* node = this;
	for (char G : prefix)
	{
		G -= 'a'; //求出该字母对应下标
		if (node->dict[G] == nullptr)
		{
			return nullptr;
		}
		node = node->dict[G];
	}
	return node;
}

Trie::Trie() :dict(26)/*指定大小对应26个字母*/, isEnd(false)
{
}

void Trie::insert(string word)
{
	Trie* node = this;
	for (char A : word)
	{
		A -= 'a';//求出该字母对应下标
		if (node->dict[A] == nullptr)
		{
			node->dict[A] = new Trie(); //结点存在即该下标对应字母存在
		}
		node = node->dict[A];
	}
	node->isEnd = true; //标记该单词终点
}

bool Trie::search(string word)
{
	Trie* node = this->searchPrefix(word);
	return node != nullptr && node->isEnd; //返回结点不为空，且为终点才存在
}

bool Trie::startsWith(string prefix)
{
	Trie* node = this->searchPrefix(prefix);
	return node != nullptr; //该前缀存在即可
}
