#include <iostream> 
//这里需要包含两个头文件
#include "State.h"  
#include "Work.h"  

using namespace std;  

void ForenoonState::writeProgram(Work* w)  
{  
	if(w->getHour()<12)  
	{  
		cout<<"当前时间："<<w->getHour()<<"点 "<<"上午工作，精神百倍"<<endl;  
	}  
	else  
	{  
		//重新设置work的状态 调用其work的writeProgram()方法，实际上是调用的work对象中
		//state的writeProgram(Work* w) 方法，看起来好像是work对象在自己改变自身的状态
		w->setState(new NoonState);  
		w->writeProgram();  
	}  
}  

void NoonState::writeProgram(Work* w)  
{  
	if(w->getHour()<13)  
	{  
		cout<<"当前时间："<<w->getHour()<<"点 "<<"饿了，午饭；犯困，午休"<<endl;  
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
		cout<<"当前时间："<<w->getHour()<<"点 "<<"下午状态还不错，继续努力"<<endl;  
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
			cout<<"当前时间："<<w->getHour()<<"点 "<<"加班哦，疲惫至极"<<endl;  
		else  
		{  
			w->setState(new SleepingState);  
			w->writeProgram();  
		}  
	}  
}  

void SleepingState::writeProgram(Work* w)  
{  
	cout<<"当前时间："<<w->getHour()<<"点 "<<"不行了，睡着了"<<endl;  
}  

void RestState::writeProgram(Work* w)  
{  
	cout<<"当前时间："<<w->getHour()<<"点 "<<"下班回家了"<<endl;  
}  

