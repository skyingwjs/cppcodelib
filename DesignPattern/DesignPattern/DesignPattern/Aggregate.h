#ifndef _AGGREGATE_H_
#define _AGGREGATE_H_

#include <vector>
#include <iostream>
#include <string>

class Iterator;
class ConcreteIterator;
class ConcreteIteratorDesc;

typedef std::string object;  
//�ۼ�������
class Aggregate{
public:
	virtual Iterator* CreateIterator()=0;
	virtual Iterator* CreateIteratorDesc()=0;
	virtual std::vector<object> *GetVector()=0;

};

//����ۼ���
class ConcreteAggregate:public Aggregate{
private:
	std::vector<object> *items;
public:
	ConcreteAggregate();
	~ConcreteAggregate();

	//������ǰ����ĵ�����
	Iterator * CreateIterator();
	//�����Ӻ���ǰ�ĵ�����
	Iterator * CreateIteratorDesc();

	std::vector<object>* GetVector();
	int Count();
	object GetElement(int index);
	void SetElement(int index,object o);


};
#endif