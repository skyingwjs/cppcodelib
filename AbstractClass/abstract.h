#ifndef __ABSTRACT__
#define __ABSTRACT__

class Base1{
public:
	virtual void display() const =0;//���麯��
};

class Base2:public Base1{
public:
	void display() const;//���ǻ���Ĺ��캯��
};


class Derived:public Base2{
public:
	void display() const;//���ǻ���Ĺ��캯��
};

void fun(Base1 *ptr);


#endif