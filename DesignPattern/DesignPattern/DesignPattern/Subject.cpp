#include "Subject.h"
#include "Observer.h"
//Subject 抽象通知者或主题
std::string Subject::getSubjectState(){
	return subjectState;
}

void Subject::setSubjectState(std::string state){
	this->subjectState=state;
}

//Boss 具体通知者或具体主题
void Boss::attach(Observer *observer){
	observers.push_back(observer);
}

void Boss::detach(Observer *observer){
	std::list<Observer *>::iterator it;
	for(it=observers.begin();it!=observers.end();it++){
		if(*it==observer){
			observers.erase(it);
			break;
		}
	}
}

void Boss::notify(){
	std::list<Observer *>::iterator it;
	for(it=observers.begin();it!=observers.end();it++){ 
		(**it).update();
	} 
}
