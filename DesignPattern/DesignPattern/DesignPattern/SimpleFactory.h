#pragma once
#ifndef __SIMPLE_FACTORY_H__
#define __SIMPLE_FACTORY_H__

class Operation{
protected:
	double numberA;
	double numberB;
public:
	void setA(double number);
	void setB(double number);
	double getA();
	double getB();
	virtual double getResult();	
};

class OperationAdd:public Operation{
	double getResult();
};

class OperationSub:public Operation{
	double getResult();
};

class OperationMul:public Operation{
	double getResult();
};

class OperationDiv:public Operation{
	double getResult();
};

class  OperationFactory{
public:
	Operation * createOperation(char type);

};
#endif