#pragma once
#ifndef __PROXY_PATTERN_H__
#define __PROXY_PATTERN_H__

#include<iostream>
#include <string>

//SchoolGril类
class SchoolGril{
private:
	std::string name;
public:
	void setName(std::string name){
		this->name=name;
	}

	std::string getName(){
		return name;
	}
};

//Subject 类,定义了RealSubect和Proxy的公用接口，这样就可以在任何使用RealSubject的
//地方使用Proxy代理

class IGiveGift{
public:
	virtual void giveDolls()=0;
	virtual void giveFlowers()=0;
	virtual void giveChocolate()=0;

};

//RealSubject类定义了Proxy所代理的真实实体
class Persuit:public IGiveGift{
private:
	SchoolGril *mm;
public:
	Persuit(SchoolGril *mm){
		this->mm=mm;
	}

	void giveDolls(){
		std::cout<<mm->getName()<<"  送你洋娃娃 "<<std::endl;
	}

	void giveFlowers()  {  
		std::cout<<mm->getName()<<"  送你鲜花"<<std::endl;  
	}  

	void giveChocolate()  {  
		std::cout<<mm->getName()<<"  送你巧克力"<<std::endl;  
	} 

};

//Proxy类 保存一个引用使得代理可以访问真实的实体，并提供一个与Subject的
//接口相同的接口，这样代理就可以用来替代实体
class Proxy:public IGiveGift
{
private:
	Persuit *gg;
public:
	Proxy(SchoolGril *mm){
		gg=new Persuit(mm);
	}
	void giveDolls(){
		gg->giveDolls();
	}
	void giveFlowers(){
		gg->giveFlowers();
	}
	void giveChocolate(){
		gg->giveChocolate();
	}

};

#endif