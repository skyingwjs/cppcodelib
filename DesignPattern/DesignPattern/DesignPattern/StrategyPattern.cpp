#include <cmath>
#include "StrategyPattern.h"


double CashNormal::acceptCash(double money){
	return money;
}



CashReturn::CashReturn(double moneyCondition,double moneyReturn){
	this->moneyCondition=moneyCondition;
	this->moneyReturn=moneyReturn;
}
double CashReturn::acceptCash(double money){
	if(money>moneyCondition)
		return money-floor(money/moneyCondition)*moneyReturn;
	return money;
}



CashRebate::CashRebate(double moneyRebate){
	this->moneyRebate=moneyRebate;
}
double CashRebate::acceptCash(double money){
	return money*moneyRebate;
}


CashContext::CashContext(int type):cs(nullptr){
	switch(type){
	case 1:
		cs=new CashNormal;
		break;
	case 2:
		cs=new CashReturn(300,100);
		break;
	case 3:
		cs=new CashRebate(0.8);
		break;
	default:;
	}
}

CashContext::~CashContext(){
	if(cs){
		delete cs;
		cs=nullptr;
	}
}

double CashContext::getResult(double money){
	return cs->acceptCash(money);
}

