#include <iostream>
#include "LRU_cache.h"
#include "PCB.h"

/*main为测试案例，参考力扣146题*/
int main()
{
	LRU_cache LRUcache = LRU_cache(2); //移动构造函数，设置容量大小为2
	LRUcache.put(1, 100);
	LRUcache.put(2, 200);
	if (-1 != LRUcache.get(1)) //100在容器中且100被调用，所以排在队头
	{
		cout << "1在容器中" << endl;
	}
	
	LRUcache.put(3, 300);//容器大小为2，所以队尾的200被删除
	
	if (-1 == LRUcache.get(2))
	{
		cout << "2不在容器中" << endl;
	}
}
