#include "Work.h"  

Work::Work()  
{  
	//Ĭ�ϵĳ�ʼ״̬
	current=new ForenoonState;  
	Hour=9;  
	finish=false;  
}  

Work::~Work()  
{  
	if(current!=0)  
		delete current;  
}  

double Work::getHour()  
{  
	return Hour;  
}  
void Work::setHour(double HOUR)  
{  
	Hour=HOUR;  
}  

bool Work::getFinish()  
{  
	return finish;  
}  
void Work::setFinish(bool FINISH)  
{  
	finish=FINISH;  
}  

void Work::setState(State* s)  
{  
	if(current!=0)  
		delete current;  

	current=s;  
}  

//����State��� writeProgram��Work *w����������Ҫͨ���˷����ı�Work����
//��Context��������״̬
void Work::writeProgram()  
{  
	current->writeProgram(this);  
}  
