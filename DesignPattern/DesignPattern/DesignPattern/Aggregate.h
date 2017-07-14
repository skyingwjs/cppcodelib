#ifndef _AGGREGATE_H_
#define _AGGREGATE_H_

#include <vector>
#include <iostream>
#include <string>

class Iterator;
class ConcreteIterator;
class ConcreteIteratorDesc;

typedef std::string object;  
//聚集抽象类
class Aggregate{
public:
	virtual Iterator* CreateIterator()=0;
	virtual Iterator* CreateIteratorDesc()=0;
	virtual std::vector<object> *GetVector()=0;

};

//具体聚集类
class ConcreteAggregate:public Aggregate{
private:
	std::vector<object> *items;
public:
	ConcreteAggregate();
	~ConcreteAggregate();

	//创建从前往后的迭代器
	Iterator * CreateIterator();
	//创建从后往前的迭代器
	Iterator * CreateIteratorDesc();

	std::vector<object>* GetVector();
	int Count();
	object GetElement(int index);
	void SetElement(int index,object o);


};
#endif