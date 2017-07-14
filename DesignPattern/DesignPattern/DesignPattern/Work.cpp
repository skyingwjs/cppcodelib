#include "Work.h"  

Work::Work()  
{  
	//默认的初始状态
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

//调用State类的 writeProgram（Work *w）方法，主要通过此方法改变Work对象
//（Context）的自身状态
void Work::writeProgram()  
{  
	current->writeProgram(this);  
}  
