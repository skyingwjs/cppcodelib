#ifndef _COMPOSITE_PATTERN_H_  
#define _COMPOSITE_PATTERN_H_  

#include <iostream>  
#include <list>  
#include <string>  

//Component���˴�Ϊ����˾��  
class Company  
{  
protected:  
	std::string name;  

public:  
	Company(std::string name)  
	{  
		this->name=name;  
	}  

	//���ӽڵ�  
	virtual void Add(Company* c)=0;  
	//ɾ���ڵ�  
	virtual void Remove(Company* c)=0;  
	//չʾ  
	virtual void Display(int depth)=0;  
	//ְ��  
	virtual void LineOfDuty()=0;  

	//���������  
	inline bool operator==(const Company &company) const  
	{  
		return this->name==company.name;  
	}  
};  

//Composite�����幫˾��  
class ConcreteCompany:public Company  
{  
private:  
	std::list<Company*> *children;  

public:  
	ConcreteCompany(std::string name):Company(name)  
	{  
		children=new std::list<Company*>;  
	}  

	~ConcreteCompany()  
	{  
		for(std::list<Company*>::iterator it=children->begin();it!=children->end();it++)  
			delete *it;  
		delete children;  
	}  

	//����Ҷ�ӽڵ�  
	void Add(Company* c)  
	{  
		children->push_back(c);  
	}  

	//ɾ��Ҷ�ӽڵ�  
	void Remove(Company* c)  
	{  
		for(std::list<Company*>::iterator it=children->begin();it!=children->end();it++)  
		{  
			if(**it==*c)  
			{  
				children->erase(it);  
				break;  
			}  
		}  
	}  

	//��ӡ  
	void Display(int depth)  
	{  
		for(int i=0;i<depth;i++)  
			std::cout<<"-";  
		std::cout<<name<<std::endl;  

		for(std::list<Company*>::iterator it=children->begin();it!=children->end();it++)  
			(*it)->Display(depth+4);  
	}  

	//ְ��  
	void LineOfDuty()  
	{  
		for(std::list<Company*>::iterator it=children->begin();it!=children->end();it++)  
			(*it)->LineOfDuty();  
	}  
};  

//Leaf:������Դ��  
class HRDepartment:public Company  
{  
public:  
	HRDepartment(std::string name):Company(name){}  

	void Add(Company* c){}  
	void Remove(Company* c){}  
	void Display(int depth)  
	{  
		for(int i=0;i<depth;i++)  
			std::cout<<"-";  
		std::cout<<name<<std::endl;  
	}  
	void LineOfDuty()  
	{  
		std::cout<<name<<"  Ա����Ƹ��ѵ����"<<std::endl;  
	}  
};  

//Leaf:����  
class FinanceDepartment:public Company  
{  
public:  
	FinanceDepartment(std::string name):Company(name){}  

	void Add(Company* c){}  
	void Remove(Company* c){}  
	void Display(int depth)  
	{  
		for(int i=0;i<depth;i++)  
			std::cout<<"-";  
		std::cout<<name<<std::endl;  
	}  
	void LineOfDuty()  
	{  
		std::cout<<name<<"  ��˾������֧����"<<std::endl;  
	}  
};  


#endif  
