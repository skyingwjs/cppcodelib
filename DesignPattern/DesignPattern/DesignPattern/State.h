#ifndef _STATE_H_  
#define _STATE_H_

extern class Work;  

class State  
{  
public:  
	State(){}; 
	//由具体的State子类实现此方法，改变Context（即Work对象）的状态
	virtual void writeProgram(Work* w){};  
};  

class ForenoonState:public State  
{  
public:  
	void writeProgram(Work* w);  
};  

class NoonState:public State  
{  
public:  
	void writeProgram(Work* w);  
};  

class AfternoonState:public State  
{  
public:  
	void writeProgram(Work* w);  
};  

class EveningState:public State  
{  
public:  
	void writeProgram(Work* w);  
};  

class SleepingState:public State  
{  
public:  
	void writeProgram(Work* w);  
};  

class RestState:public State  
{  
public:  
	void writeProgram(Work* w);  
};  

#endif  
