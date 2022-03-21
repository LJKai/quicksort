#include "PCB.h"

PCB::PCB():key(0), value(0), prev(nullptr), next(nullptr)
{
}

PCB::PCB(int _key, int _value):key(_key), value(_value), prev(nullptr), next(nullptr)
{
}

