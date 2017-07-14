#pragma once
#ifndef __PERSON_H__  
#define __PERSON_H__  
#include <string>  
#include <iostream>  

//ConcreteComponent��Component  
class Person  
{  
private:  
	std::string name;  

public:  
	Person(){};  
	Person(std::string name)  
	{  
		this->name=name;  
	}  
	virtual void Show()  
	{  
		std::cout<<"װ�ε�"<<name<<std::endl;  
	}  
};       



//Decorator��  
class Finery:public Person  
{  
protected:  
	Person* component;  

public:  
	void Decorator(Person* component)  
	{  
		this->component=component;  
	}  
	void Show()  
	{  
		if(component!=NULL)  
			component->Show();  
	}  
};  

//������һϵ��ConcreteDecorator��  
class TShirts:public Finery  
{  
public:  
	void Show()  
	{  
		std::cout<<"��T��  ";  
		Finery::Show();  
	}     
};  

//ConcreteDecorator��  
class BigTrouser:public Finery  
{  
public:  
	void Show()  
	{  
		std::cout<<"���  ";  
		Finery::Show();  
	}     
};  

//ConcreteDecorator��  
class Sneakers:public Finery  
{  
public:  
	void Show()  
	{  
		std::cout<<"����Ь  ";  
		Finery::Show();  
	}  
};  

//ConcreteDecorator��  
class Suit:public Finery  
{  
public:  
	void Show()  
	{  
		std::cout<<"��װ  ";  
		Finery::Show();  
	}  
};  

//ConcreteDecorator��  
class Tie:public Finery  
{  
public:  
	void Show()  
	{  
		std::cout<<"���  ";  
		Finery::Show();  
	}  
};  

//ConcreteDecorator��  
class LeatherShoes:public Finery  
{  
public:  
	void Show()  
	{  
		std::cout<<"ƤЬ  ";  
		Finery::Show();  
	}     
};  

#endif  




