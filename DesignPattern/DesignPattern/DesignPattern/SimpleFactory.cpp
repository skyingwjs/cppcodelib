#include "SimpleFactory.h"
void Operation::setA(double number){
	numberA=number;
}

void Operation::setB(double number){
	numberB=number;
} 

double Operation::getA(){
	return numberA;
}

double Operation::getB(){
	return numberB;
}

double Operation::getResult(){
	double result=0;
	return result;
}


double OperationAdd::getResult(){
	double result=0;
	result=numberA+numberB;
	return result;
}

double OperationSub::getResult(){
	double result=0;
	result=numberA-numberB;
	return result;
}

double OperationMul::getResult(){
	double result=0;
	result=numberA*numberB;
	return result;
}

double OperationDiv::getResult(){
	double result=0;
	if(numberB!=0){
		result=numberA/numberB;
	}
	return result;
}

Operation * OperationFactory::createOperation(char type){
	Operation *oper=nullptr;
	switch(type){
	case '+':
		oper=new OperationAdd;
		break;
	case '-':
		oper=new OperationSub;
		break;
	case '*':
		oper=new OperationMul;
		break;
	case '/':
		oper=new OperationDiv;
		break;
	}
	return oper;
}

