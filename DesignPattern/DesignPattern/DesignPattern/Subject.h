#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <iostream>
#include <string>
#include <list>


class Observer;

//Subject 抽象通知者或主题
class Subject{
protected:
	std::string subjectState;

public:
	virtual void attach(Observer *observer)=0;
	virtual void detach(Observer *observer)=0;
	virtual void notify()=0;
	std::string getSubjectState();
	void setSubjectState(std::string state);
};
//Boss 具体通知者或具体主题
class Boss:public Subject{
private:
	std::list<Observer *> observers;
	std::string action;

public:
	void attach(Observer *observer);
	void detach(Observer *observer);
	void notify();
};


#endif