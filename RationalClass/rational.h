/************************************************************************
���������ʵ�֣��Ӽ��˳����������
************************************************************************/

#ifndef __RATIONAL_H__
#define __RATIONAL_H__

#include <iostream>
using namespace std;

class Rational{

private:
	long long _p;//����
	long long _q;//��ĸ
	void simplify();//����

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

	Rational operator++ (int);//��������
	Rational operator-- (int);
	Rational& operator++ ();//ǰ������
	Rational& operator-- ();
	Rational operator- () const;
	Rational operator+ () const;

	Rational pow (unsigned exp) const;//����
	Rational inverse() const;//����
};

#endif

