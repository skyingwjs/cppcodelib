#include <iostream> 
//������Ҫ��������ͷ�ļ�
#include "State.h"  
#include "Work.h"  

using namespace std;  

void ForenoonState::writeProgram(Work* w)  
{  
	if(w->getHour()<12)  
	{  
		cout<<"��ǰʱ�䣺"<<w->getHour()<<"�� "<<"���繤��������ٱ�"<<endl;  
	}  
	else  
	{  
		//��������work��״̬ ������work��writeProgram()������ʵ�����ǵ��õ�work������
		//state��writeProgram(Work* w) ������������������work�������Լ��ı������״̬
		w->setState(new NoonState);  
		w->writeProgram();  
	}  
}  

void NoonState::writeProgram(Work* w)  
{  
	if(w->getHour()<13)  
	{  
		cout<<"��ǰʱ�䣺"<<w->getHour()<<"�� "<<"���ˣ��緹������������"<<endl;  
	}  
	else  
	{  
		w->setState(new AfternoonState);  
		w->writeProgram();  
	}  
}  

void AfternoonState::writeProgram(Work* w)  
{  
	if(w->getHour()<17)  
		cout<<"��ǰʱ�䣺"<<w->getHour()<<"�� "<<"����״̬����������Ŭ��"<<endl;  
	else  
	{  
		w->setState(new EveningState);  
		w->writeProgram();  
	}  
}  

void EveningState::writeProgram(Work* w)  
{  
	if(w->getFinish())  
	{  
		w->setState(new RestState);  
		w->writeProgram();  
	}  
	else  
	{  
		if(w->getHour()<21)  
			cout<<"��ǰʱ�䣺"<<w->getHour()<<"�� "<<"�Ӱ�Ŷ��ƣ������"<<endl;  
		else  
		{  
			w->setState(new SleepingState);  
			w->writeProgram();  
		}  
	}  
}  

void SleepingState::writeProgram(Work* w)  
{  
	cout<<"��ǰʱ�䣺"<<w->getHour()<<"�� "<<"�����ˣ�˯����"<<endl;  
}  

void RestState::writeProgram(Work* w)  
{  
	cout<<"��ǰʱ�䣺"<<w->getHour()<<"�� "<<"�°�ؼ���"<<endl;  
}  

