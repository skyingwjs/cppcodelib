#include "Subject.h"
#include "Observer.h"
//Observer ����۲���
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


//StockObserver ����۲��� ��Ʊ�۲���
StockObserver::StockObserver(){

}

StockObserver::StockObserver(std::string name,Subject *sub){
	this->name=name;
	this->sub=sub;
}

void StockObserver::update(){
	std::cout<<sub->getSubjectState()<<""<<name<<"�رչ������飬��������"<<std::endl;
}


//NBAObserver ����۲��� NBA�۲��� 
NBAObserver::NBAObserver(){

}

NBAObserver::NBAObserver(std::string name,Subject *sub){
	this->name=name;
	this->sub=sub;
}

void NBAObserver::update(){
	std::cout<<sub->getSubjectState()<<""<<name<<"�ر�NBAֱ������������"<<std::endl;
}

