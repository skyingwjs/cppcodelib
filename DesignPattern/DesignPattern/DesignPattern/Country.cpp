#include "Country.h"  
#include <string>  
#include <iostream>  

using namespace std;  

/************************************************************************
具体的Country对象让中介者mediator帮其发送消息给其他国家
************************************************************************/
void USA::Declare(string message)  
{  
	mediator->Declare(message,this);  
}  
/************************************************************************
具体的国家获取的消息 由中介传送过来 详见方法
void UnitedNationsSecurityCouncil::Declare(string message,Country* colleague)
************************************************************************/
void USA::GetMessage(string message)  
{  
	cout<<"美国获得对方信息："<<message<<endl;  
}  

void Iraq::Declare(string message)  
{  
	mediator->Declare(message,this);  
}  

void Iraq::GetMessage(string message)  
{  
	cout<<"伊拉克获得对方信息："<<message<<endl;  
}  
