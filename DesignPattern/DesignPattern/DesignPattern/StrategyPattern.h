#pragma  once
#ifndef __STRATEGY_PETTERN_H__
#define __STRATEGY_PETTERN_H__

class CashSuper{
public:
	virtual double acceptCash(double money)=0;
};

class CashNormal:public CashSuper{
public:
	double acceptCash(double money);
};

class CashReturn:public CashSuper{
private:
	double moneyCondition;
	double moneyReturn;
public:
	CashReturn(double moneyCondition,double moneyReturn);
	double acceptCash(double money);

};

class CashRebate:public CashSuper{
private:
	double moneyRebate;
public:
	CashRebate(double moneyRebate);
	double acceptCash(double money);
};


class CashContext{
private:
	CashSuper *cs;
public:
	CashContext(int type);
	~CashContext();
	double getResult(double money);
};
#endif
