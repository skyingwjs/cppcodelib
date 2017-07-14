#ifndef _UNITED_NATIONS_H_
#define _UNITED_NATIONS_H_
class Country;
using namespace std;

//Mediator ���Ϲ�
class UnitedNations{
public:
	virtual void SetColleague1(Country *c)=0;
	virtual void SetColleague2(Country *c)=0;
	virtual void Declare(string message,Country *colleague)=0;
};

//ConcreteMediator ���Ϲ������
class UnitedNationsSecurityCouncil:public UnitedNations  
{  
private:  
	Country* colleague1;  
	Country* colleague2;  

public:  
	void SetColleague1(Country* c);  
	void SetColleague2(Country* c);  
	void Declare(string message, Country* colleague);  

};   
#endif