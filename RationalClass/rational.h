/************************************************************************
有理数类的实现：加减乘除、输入输出
************************************************************************/

#ifndef __RATIONAL_H__
#define __RATIONAL_H__

#include <iostream>
using namespace std;

class Rational{

private:
	long long _p;//分子
	long long _q;//分母
	void simplify();//化简

public:
	Rational();
	Rational (long long p, long long Q = 1);
	Rational (const Rational&);

	Rational& operator= (const Rational&);
	Rational& operator+= (const Rational&);
	Rational& operator-= (const Rational&);
	Rational& operator*= (const Rational&);
	Rational& operator/= (const Rational&);

	friend ostream& operator<< (ostream&, const Rational&);
	friend istream& operator>> (istream&, Rational&);

	Rational operator+ (const Rational&);
	Rational operator+ (long long) const;
	friend Rational operator+ (long long, const Rational&);

	Rational operator- (const Rational&);
	Rational operator- (long long) const;
	friend Rational operator- (long long, const Rational&);

	Rational operator* (const Rational&);
	Rational operator* (long long) const;
	friend Rational operator* (long long, const Rational&);

	Rational operator/ (const Rational&);
	Rational operator/ (long long) const;
	friend Rational operator/ (long long, const Rational&);

	bool operator== (const Rational&) const;
	bool operator== (long long) const;
	friend bool operator== (long long, const Rational&);

	bool operator!= (const Rational&) const;
	bool operator!= (long long) const;
	friend bool operator!= (long long, const Rational&);

	bool operator> (const Rational&) const;
	bool operator> (long long) const;
	friend bool operator> (long long, const Rational&);

	bool operator< (const Rational&) const;
	bool operator< (long long) const;
	friend bool operator< (long long, const Rational&);

	bool operator>= (const Rational&) const;
	bool operator>= (long long) const;
	friend bool operator>= (long long, const Rational&);

	bool operator<= (const Rational&) const;
	bool operator<= (long long) const;
	friend bool operator<= (long long, const Rational&);

	Rational operator++ (int);//后置自增
	Rational operator-- (int);
	Rational& operator++ ();//前置自增
	Rational& operator-- ();
	Rational operator- () const;
	Rational operator+ () const;

	Rational pow (unsigned exp) const;//求幂
	Rational inverse() const;//求倒数
};

#endif

