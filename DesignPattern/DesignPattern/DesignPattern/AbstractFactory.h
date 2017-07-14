#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_
#include <iostream>  
#include <cstdlib>    
using namespace std;  

//���ݿ���User  
class User  
{  
private:  
	int id;  
	string name;  
public:  
	int getID()  
	{  
		return id;  
	}  
	string getName()  
	{  
		return name;  
	}  
	void setID(int ID)  
	{  
		this->id=ID;  
	}  
	void setName(string NAME)  
	{  
		this->name=NAME;  
	}  
};  


//���ݿ���Department  
class Department  
{  
private:  
	int id;  
	string name;  
public:  
	int getID()  
	{  
		return id;  
	}  
	string getName()  
	{  
		return name;  
	}  
	void setID(int ID)  
	{  
		this->id=ID;  
	}  
	void setName(string NAME)  
	{  
		this->name=NAME;  
	}  
};  

//�����ƷA��IUser�������ֲ�ͬ��ʵ�ַ���SqlServerUser��AcessUser  
class IUser{
public:
	virtual void Insert(User user)=0;
	virtual User * GetUser(int id)=0;

};

//�����ƷA1��SqlserverUser  
class SqlserverUser:public IUser  
{  
public:  
	void Insert(User user)  
	{  
		cout<<"��SQL Server�и�User��������һ����¼"<<endl;  
	}  
	User* GetUser(int id)  
	{  
		cout<<"��SQL Server�и���ID�õ�User��һ����¼"<<endl;  
		return NULL;  
	}  
};  

//�����ƷA2��AccessUser  
class AccessUser:public IUser  
{  
public:  
	void Insert(User user)  
	{  
		cout<<"��Access�и�User��������һ����¼"<<endl;  
	}  
	User* GetUser(int id)  
	{  
		cout<<"��Access�и���ID�õ�User��һ����¼"<<endl;  
		return NULL;  
	}  

};  



//�����ƷB��IDepartment�������ֲ�ͬ��ʵ�ַ���SqlserverDepartment��AccessDepartment       
class IDepartment  
{  
public:  
	virtual void Insert(Department department)=0;  
	virtual Department* GetDepartment(int id)=0;  
};  

//�����ƷB1��SqlserverDepartment  
class SqlserverDepartment:public IDepartment  
{  
public:  
	void Insert(Department department)  
	{  
		cout<<"��Sql Server�и�Department�������һ����¼"<<endl;  
	}  
	Department* GetDepartment(int id)  
	{  
		cout<<"��SQL Server�и���ID�õ�Department���һ����¼"<<endl;  
		return NULL;  
	}  
};  

//�����ƷB2��AccessDepartment  
class AccessDepartment:public IDepartment  
{  
public:  
	void Insert(Department department)  
	{  
		cout<<"��Access�и�Department�������һ����¼"<<endl;  
	}  
	Department* GetDepartment(int id)  
	{  
		cout<<"��Access�и���ID�õ�Department���һ����¼"<<endl;  
		return NULL;  
	}  
};  

//���󹤳���IFactory ����������Ĺ���SqlServerFactory��AccessFactory   
class IFactory  
{  
public:  
	virtual IUser* CreateUser()=0;  
	virtual IDepartment* CreateDepartment()=0;  
};  

//���幤��1��SqlServerFactory  
class SqlserverFactory:public IFactory  
{  
public:  
	IUser* CreateUser()  
	{  
		return new SqlserverUser;  
	}  

	IDepartment* CreateDepartment()  
	{  
		return new SqlserverDepartment;  
	}  
};  

//���幤��2��AccessFactory  
class AccessFactory:public IFactory  
{  
public:  
	IUser* CreateUser()  
	{  
		return new AccessUser;  
	}  

	IDepartment* CreateDepartment()  
	{  
		return new AccessDepartment;  
	}  
};  










#endif