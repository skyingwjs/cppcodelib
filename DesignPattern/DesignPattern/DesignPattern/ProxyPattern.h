#pragma once
#ifndef __PROXY_PATTERN_H__
#define __PROXY_PATTERN_H__

#include<iostream>
#include <string>

//SchoolGril��
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

//Subject ��,������RealSubect��Proxy�Ĺ��ýӿڣ������Ϳ������κ�ʹ��RealSubject��
//�ط�ʹ��Proxy����

class IGiveGift{
public:
	virtual void giveDolls()=0;
	virtual void giveFlowers()=0;
	virtual void giveChocolate()=0;

};

//RealSubject�ඨ����Proxy���������ʵʵ��
class Persuit:public IGiveGift{
private:
	SchoolGril *mm;
public:
	Persuit(SchoolGril *mm){
		this->mm=mm;
	}

	void giveDolls(){
		std::cout<<mm->getName()<<"  ���������� "<<std::endl;
	}

	void giveFlowers()  {  
		std::cout<<mm->getName()<<"  �����ʻ�"<<std::endl;  
	}  

	void giveChocolate()  {  
		std::cout<<mm->getName()<<"  �����ɿ���"<<std::endl;  
	} 

};

//Proxy�� ����һ������ʹ�ô�����Է�����ʵ��ʵ�壬���ṩһ����Subject��
//�ӿ���ͬ�Ľӿڣ���������Ϳ����������ʵ��
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