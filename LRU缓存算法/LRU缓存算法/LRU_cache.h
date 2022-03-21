#pragma once
#include <unordered_map>
#include "PCB.h"
using namespace std;

class LRU_cache
{
private:
	unordered_map<int, PCB*>cache; //存储所有结点，便于快速查找
	/*头结点和尾结点*/
	PCB* head;
	PCB* tail;
	int size;//已存数据
	int capacity; //容量大小
public:
	LRU_cache(int _capacity);
	LRU_cache(LRU_cache&& cache); //移动构造函数
	int get(int key);
	void put(int key, int value);
	void addToHead(PCB* node);
	void removeNode(PCB* node);
	void moveToHead(PCB* node);
	PCB* removeTail();
};

