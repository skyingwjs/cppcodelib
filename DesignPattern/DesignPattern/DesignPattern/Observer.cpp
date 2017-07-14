#include "Subject.h"
#include "Observer.h"
//Observer 抽象观察者
Observer::Observer(){

}

Observer::Observer(std::string name,Subject *sub){
	this->name=name;
	this->sub=sub;
}

void Observer::update(){
	std::cout<<"Observer.update()"<<std::endl;
}

bool Observer::operator==(const Observer & observer)const{
	return (this->name==observer.name)&&(this->sub==observer.sub);
}


//StockObserver 具体观察者 股票观察者
StockObserver::StockObserver(){

}

StockObserver::StockObserver(std::string name,Subject *sub){
	this->name=name;
	this->sub=sub;
}

void StockObserver::update(){
	std::cout<<sub->getSubjectState()<<""<<name<<"关闭股市行情，继续工作"<<std::endl;
}


//NBAObserver 具体观察者 NBA观察者 
NBAObserver::NBAObserver(){

}

NBAObserver::NBAObserver(std::string name,Subject *sub){
	this->name=name;
	this->sub=sub;
}

void NBAObserver::update(){
	std::cout<<sub->getSubjectState()<<""<<name<<"关闭NBA直播，继续工作"<<std::endl;
}

