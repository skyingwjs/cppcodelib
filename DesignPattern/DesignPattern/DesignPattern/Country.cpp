#include "Country.h"  
#include <string>  
#include <iostream>  

using namespace std;  

/************************************************************************
�����Country�������н���mediator���䷢����Ϣ����������
************************************************************************/
void USA::Declare(string message)  
{  
	mediator->Declare(message,this);  
}  
/************************************************************************
����Ĺ��һ�ȡ����Ϣ ���н鴫�͹��� �������
void UnitedNationsSecurityCouncil::Declare(string message,Country* colleague)
************************************************************************/
void USA::GetMessage(string message)  
{  
	cout<<"������öԷ���Ϣ��"<<message<<endl;  
}  

void Iraq::Declare(string message)  
{  
	mediator->Declare(message,this);  
}  

void Iraq::GetMessage(string message)  
{  
	cout<<"�����˻�öԷ���Ϣ��"<<message<<endl;  
}  
