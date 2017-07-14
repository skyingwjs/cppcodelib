#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <vector>
#include <iostream>
#include "Aggregate.h"

typedef std::string object;

//迭代器抽象类
class Iterator{
public:
	virtual object First()=0;
	virtual object Next()=0;
	virtual bool IsDone()=0;
	virtual object CurrentItem()=0;
};

//具体迭代器类，从前往后的迭代器
class ConcreteIterator:public Iterator{
private:
	ConcreteAggregate* aggregate;
	int current;

public:
	ConcreteIterator(Aggregate* aggregate);
	object First();
	object Next();
	bool IsDone();
	object CurrentItem();
};

//具体迭代器类，从后往前的迭代器
class ConcreteIteratorDesc:public Iterator{
private:
	ConcreteAggregate* aggregate;
	int current;

public:
	ConcreteIteratorDesc(Aggregate* aggregate);
	object First();
	object Next();
	bool IsDone();
	object CurrentItem();
};

#endif