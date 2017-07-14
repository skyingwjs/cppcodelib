#pragma once
#ifndef __PROTOTYPE_PATTERN_H__
#define __PROTOTYPE_PATTERN_H__

#include <iostream>
#include <string>
using namespace std;
//���������ࣺWorkExperience
class WorkExperience{
private:
	string workDate;
	string company;
public:
	WorkExperience(){

	}
	~WorkExperience(){

	}

	//����¡���õĹ��캯��,���¹�����һ���µĶ������
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
		//���� ����¡���õĹ��캯��WorkExperience��WorkExperience�� 
		return new WorkExperience(this);
	}
};

//ԭ���� ����һ����¡����Ľӿ�

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

//����ԭ���࣬��ConcretePrototype�࣬������Ϊ����Resume�࣬ʵ��һ����¡����Ĳ�����  
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

	//����¡���õĹ��캯��
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
		cout<<"��������  "<<work->getWorkDate()<<"  "<<work->getCompany()<<endl;  
	}  

	//��¡
	Resume *clone(){
		//���� ����¡�������õĹ��캯��
		Resume *cloneResume=new Resume(work);
		cloneResume->name=this->name;
		cloneResume->age=this->age;
		cloneResume->sex=this->sex;
		return cloneResume;
	}

};



#endif