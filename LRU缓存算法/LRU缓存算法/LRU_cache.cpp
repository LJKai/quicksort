#include "LRU_cache.h"

LRU_cache::LRU_cache(int _capacity):capacity(_capacity)
{
	head = new PCB();
	tail = new PCB();
	head->next = tail;
	tail->prev = head;
	size = 0;
}

LRU_cache::LRU_cache(LRU_cache&& cache):capacity(cache.capacity), head(cache.head), 
tail(cache.tail),size(cache.size)
{
	cache.head = nullptr;
	cache.tail = nullptr;
}

int LRU_cache::get(int key)
{
	if (!cache.count(key))
	{
		return -1;
	}
	PCB* node = cache[key];
	moveToHead(node);
	return node->value;
}

void LRU_cache::put(int key, int value)
{
	if (!cache.count(key))
	{
		PCB* node = new PCB(key, value);
		cache[key] = node;
		addToHead(node);
		++size;
		if (size > capacity)
		{
			PCB* node = removeTail();
			cache.erase(node->key);
			delete node;
			size--;
		}
	}
	else
	{
		PCB* node = cache[key];
		node->value = value;
		moveToHead(node);
	}
}

void LRU_cache::addToHead(PCB* node)
{
	node->prev = head;
	node->next = head->next;
	head->next->prev = node;
	head->next = node;
}

void LRU_cache::removeNode(PCB* node) //仅仅只是移出队列，并未delete
{
	node->next->prev = node->prev;
	node->prev->next = node->next;
}

void LRU_cache::moveToHead(PCB* node)
{
	removeNode(node);
	addToHead(node);
}

PCB* LRU_cache::removeTail()
{
	PCB* node = tail->prev;
	removeNode(node);
	return node;
}
