#ifndef __FACADE_H__ 
#define __FACADE_H__ 

#include <iostream>  
#include <string>  

//SubSystem Class��ʵ����ϵͳ�Ĺ��ܣ�����Facade����ָ�ɵ�����ע��������û��Facade�κ���Ϣ����û�ж�Facade��������á�  
//�������ĸ���ϵͳ����  
class SubSystemOne  
{  
public:  
	void MethodOne()  
	{  
		std::cout<<"��ϵͳ����һ"<<std::endl;  
	}  
};  

class SubSystemTwo  
{  
public:  
	void MethodTwo()  
	{  
		std::cout<<"��ϵͳ������"<<std::endl;  
	}  
};  

class SubSystemThree  
{  
public:  
	void MethodThree()  
	{  
		std::cout<<"��ϵͳ������"<<std::endl;  
	}  
};  

class SubSystemFour  
{  
public:  
	void MethodFour()  
	{  
		std::cout<<"��ϵͳ������"<<std::endl;  
	}  
};  

//Facade Class������֪࣬������Щ��ϵͳ�࣬���������󣬽��ͻ������������ʵ�����ϵͳ����  
class Facade  
{  
private:  
	SubSystemOne* one;  
	SubSystemTwo* two;  
	SubSystemThree* three;  
	SubSystemFour* four;  

public:  
	Facade()  
	{  
		one=new SubSystemOne();  
		two=new SubSystemTwo();  
		three=new SubSystemThree();  
		four=new SubSystemFour();  
	}  
	~Facade()  
	{  
		delete one;  
		delete two;  
		delete three;  
		delete four;  
	}  

	void MethodA()  
	{  
		std::cout<<"������A����------"<<std::endl;  
		one->MethodOne();  
		two->MethodTwo();  
		four->MethodFour();  
		std::cout<<std::endl;  
	}  

	void MethodB()  
	{  
		std::cout<<"������B����------"<<std::endl;  
		two->MethodTwo();  
		three->MethodThree();  
		std::cout<<std::endl;  
	}  
};  
#endif  


