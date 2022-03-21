#pragma once
class PCB
{
public:
	int key, value;
	PCB* prev;
	PCB* next;
	PCB();
	PCB(int _key, int _value);
};

