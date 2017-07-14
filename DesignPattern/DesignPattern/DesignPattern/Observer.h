#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include <iostream>
#include <string>
#include <list>
#include "Subject.h"

//Observer 抽象观察者
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

//StockObserver 具体观察者 股票观察者
class StockObserver:public Observer{
public:
	StockObserver();
	StockObserver(std::string name,Subject *sub);
	void update();
};

//NBAObserver 具体观察者 NBA观察者 
class NBAObserver:public Observer{
public:
	NBAObserver();
	NBAObserver(std::string name,Subject *sub);
	void update();
};

#endif