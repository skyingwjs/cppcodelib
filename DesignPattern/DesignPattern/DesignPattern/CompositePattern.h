#ifndef _COMPOSITE_PATTERN_H_  
#define _COMPOSITE_PATTERN_H_  

#include <iostream>  
#include <list>  
#include <string>  

//Component：此处为抽象公司类  
class Company  
{  
protected:  
	std::string name;  

public:  
	Company(std::string name)  
	{  
		this->name=name;  
	}  

	//增加节点  
	virtual void Add(Company* c)=0;  
	//删除节点  
	virtual void Remove(Company* c)=0;  
	//展示  
	virtual void Display(int depth)=0;  
	//职责  
	virtual void LineOfDuty()=0;  

	//运算符重载  
	inline bool operator==(const Company &company) const  
	{  
		return this->name==company.name;  
	}  
};  

//Composite：具体公司类  
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

	//增加叶子节点  
	void Add(Company* c)  
	{  
		children->push_back(c);  
	}  

	//删除叶子节点  
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

	//打印  
	void Display(int depth)  
	{  
		for(int i=0;i<depth;i++)  
			std::cout<<"-";  
		std::cout<<name<<std::endl;  

		for(std::list<Company*>::iterator it=children->begin();it!=children->end();it++)  
			(*it)->Display(depth+4);  
	}  

	//职责  
	void LineOfDuty()  
	{  
		for(std::list<Company*>::iterator it=children->begin();it!=children->end();it++)  
			(*it)->LineOfDuty();  
	}  
};  

//Leaf:人力资源部  
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
		std::cout<<name<<"  员工招聘培训管理"<<std::endl;  
	}  
};  

//Leaf:财务部  
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
		std::cout<<name<<"  公司财务收支管理"<<std::endl;  
	}  
};  


#endif  
