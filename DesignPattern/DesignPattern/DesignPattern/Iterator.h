#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <vector>
#include <iostream>
#include "Aggregate.h"

typedef std::string object;

//������������
class Iterator{
public:
	virtual object First()=0;
	virtual object Next()=0;
	virtual bool IsDone()=0;
	virtual object CurrentItem()=0;
};

//����������࣬��ǰ����ĵ�����
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

//����������࣬�Ӻ���ǰ�ĵ�����
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