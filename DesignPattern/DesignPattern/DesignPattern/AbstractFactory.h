#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_
#include <iostream>  
#include <cstdlib>    
using namespace std;  

//数据库表项：User  
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


//数据库表项：Department  
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

//抽象产品A：IUser，有两种不同的实现方法SqlServerUser和AcessUser  
class IUser{
public:
	virtual void Insert(User user)=0;
	virtual User * GetUser(int id)=0;

};

//具体产品A1：SqlserverUser  
class SqlserverUser:public IUser  
{  
public:  
	void Insert(User user)  
	{  
		cout<<"在SQL Server中给User表增加了一条记录"<<endl;  
	}  
	User* GetUser(int id)  
	{  
		cout<<"在SQL Server中根据ID得到User表一条记录"<<endl;  
		return NULL;  
	}  
};  

//具体产品A2：AccessUser  
class AccessUser:public IUser  
{  
public:  
	void Insert(User user)  
	{  
		cout<<"在Access中给User表增加了一条记录"<<endl;  
	}  
	User* GetUser(int id)  
	{  
		cout<<"在Access中根据ID得到User表一条记录"<<endl;  
		return NULL;  
	}  

};  



//抽象产品B：IDepartment，有两种不同的实现方法SqlserverDepartment和AccessDepartment       
class IDepartment  
{  
public:  
	virtual void Insert(Department department)=0;  
	virtual Department* GetDepartment(int id)=0;  
};  

//具体产品B1：SqlserverDepartment  
class SqlserverDepartment:public IDepartment  
{  
public:  
	void Insert(Department department)  
	{  
		cout<<"在Sql Server中给Department表添加了一条记录"<<endl;  
	}  
	Department* GetDepartment(int id)  
	{  
		cout<<"在SQL Server中根据ID得到Department表的一条记录"<<endl;  
		return NULL;  
	}  
};  

//具体产品B2：AccessDepartment  
class AccessDepartment:public IDepartment  
{  
public:  
	void Insert(Department department)  
	{  
		cout<<"在Access中给Department表添加了一条记录"<<endl;  
	}  
	Department* GetDepartment(int id)  
	{  
		cout<<"在Access中根据ID得到Department表的一条记录"<<endl;  
		return NULL;  
	}  
};  

//抽象工厂：IFactory 有两个具体的工厂SqlServerFactory和AccessFactory   
class IFactory  
{  
public:  
	virtual IUser* CreateUser()=0;  
	virtual IDepartment* CreateDepartment()=0;  
};  

//具体工厂1：SqlServerFactory  
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

//具体工厂2：AccessFactory  
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