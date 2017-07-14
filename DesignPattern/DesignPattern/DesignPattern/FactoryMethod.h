#pragma once
#ifndef __FACTORY_METHOD_H__
#define __FACTORY_METHOD_H__
#include <iostream>  
#include <cstdlib>  
#include "SimpleFactory.h"

////�����Ʒ��  
//class Operation  
//{  
//protected:  
//	double numberA;  
//	double numberB;  
//
//public:  
//	double getA()  
//	{  
//		return numberA;  
//	}  
//	double getB()  
//	{  
//		return numberB;  
//	}  
//	void setA(double number)  
//	{  
//		numberA=number;  
//	}  
//	void setB(double number)  
//	{  
//		numberB=number;  
//	}  
//
//	virtual double GetResult()  
//	{  
//		double result=0;  
//		return result;  
//	}  
//};  
//
////�������ĸ������Ʒ��  
//class OperationAdd:public Operation  
//{  
//public:  
//	double GetResult()  
//	{  
//		double result=0;  
//		result=numberA+numberB;  
//		return result;  
//	}  
//};  
//
//class OperationSub:public Operation  
//{  
//public:  
//	double GetResult()  
//	{  
//		double result=0;  
//		result=numberA-numberB;  
//		return result;  
//	}  
//};  
//
//class OperationMul:public Operation  
//{  
//public:  
//	double GetResult()  
//	{  
//		double result=0;  
//		result=numberA*numberB;  
//		return result;  
//	}  
//};  
//
//class OperationDiv:public Operation  
//{  
//public:  
//	double GetResult()  
//	{  
//		double result=0;  
//		if(numberB!=0)  
//			result=numberA/numberB;  
//		return result;  
//	}  
//}; 

//�����Ʒ��;����Ʒ�� ������"SimpleFactory.h"

//���󹤳���
class AbstractFactory{
public:
	virtual Operation* createOperation(){
		return new Operation;
	}
};

//�������ĸ�����Ĺ����࣬�ֱ����������ĸ�����Ĳ�Ʒ
class AddFactory:public AbstractFactory{
public:
	Operation *createOperation(){
		Operation *oper=new OperationAdd;
		return oper;
	}
};

class SubFactory:public AbstractFactory{
public:
	Operation *createOperation(){
		Operation  *oper=new OperationSub;
		return oper;
	}
};

class MulFactory:public AbstractFactory{
public:
	Operation *createOperation(){
		Operation *oper=new OperationMul;
		return oper;
	}
};

class DivFactory:public AbstractFactory{
public:
	Operation *createOperation(){
		Operation  *oper=new OperationDiv;
		return oper;
	}
};

#endif
