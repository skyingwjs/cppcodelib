#pragma once
#ifndef __PROTOTYPE_PATTERN_H__
#define __PROTOTYPE_PATTERN_H__

#include <iostream>
#include <string>
using namespace std;
//工作经验类：WorkExperience
class WorkExperience{
private:
	string workDate;
	string company;
public:
	WorkExperience(){

	}
	~WorkExperience(){

	}

	//供克隆调用的构造函数,重新构造了一个新的对象，深复制
	WorkExperience(WorkExperience *work){
		this->company=work->company;
		this->workDate=workDate;
	} 

	string getWorkDate(){
		return workDate;
	}

	void setWorkDate(string workDate){
		this->workDate=workDate;
	}

	string getCompany(){
		return company;
	}

	void setCompany(string company){
		this->company=company;
	}

	//clone
	WorkExperience *clone(){
		//调用 供克隆调用的构造函数WorkExperience（WorkExperience） 
		return new WorkExperience(this);
	}
};

//原型类 声明一个克隆自身的接口

class Prototype{
protected:
	string name;
	string age;
	string sex;
	string timeArea;
	string company;

public:
	virtual void setPersonalInfo(string sex,string age)=0;
	virtual void display()=0;
	virtual Prototype *clone()=0;
};

//具体原型类，即ConcretePrototype类，本例中为简历Resume类，实现一个克隆自身的操作。  
class Resume:public Prototype{
private:
	WorkExperience *work;

public:
	Resume(string name){
		this->name=name;
		this->work=new WorkExperience();
	}

	~Resume(){
		if (work!=NULL)
		{
			delete work;
		}
	}

	//供克隆调用的构造函数
	Resume(WorkExperience *work){
		this->work=work->clone();
	}

	void setPersonalInfo(string sex,string age){
		this->sex=sex;
		this->age=age;
	}

	void setWorkExperience(std::string workDate,std::string company)  
	{  
		work->setWorkDate(workDate);  
		work->setCompany(company);  
	}

	void display()  
	{  
		cout<<name<<"  "<<sex<<"  "<<age<<endl;  
		cout<<"工作经历  "<<work->getWorkDate()<<"  "<<work->getCompany()<<endl;  
	}  

	//克隆
	Resume *clone(){
		//调用 供克隆函数调用的构造函数
		Resume *cloneResume=new Resume(work);
		cloneResume->name=this->name;
		cloneResume->age=this->age;
		cloneResume->sex=this->sex;
		return cloneResume;
	}

};



#endif