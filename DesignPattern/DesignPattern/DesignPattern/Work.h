#ifndef _WORK_H_  
#define _WORK_H_ 

#include "State.h"  

class Work  
{  
private:  
	State* current;  
	double Hour;  
	bool finish;  

public:  
	Work();  
	~Work();  

	double getHour();  
	void setHour(double HOUR);  

	bool getFinish();  
	void setFinish(bool FINISH);  

	void setState(State* s);  

	void writeProgram();  
};  

#endif  
