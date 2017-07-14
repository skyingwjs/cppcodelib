#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include <iostream>
#include <string>
#include <list>
#include "Subject.h"

//Observer ����۲���
class Observer{
protected:
	std::string name;
	Subject *sub;

public:
	Observer();
	Observer(std::string name,Subject *sub);
	virtual void update();
	bool operator==(const Observer & observer)const;
};

//StockObserver ����۲��� ��Ʊ�۲���
class StockObserver:public Observer{
public:
	StockObserver();
	StockObserver(std::string name,Subject *sub);
	void update();
};

//NBAObserver ����۲��� NBA�۲��� 
class NBAObserver:public Observer{
public:
	NBAObserver();
	NBAObserver(std::string name,Subject *sub);
	void update();
};

#endif