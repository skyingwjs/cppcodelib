#ifndef __ABSTRACT__
#define __ABSTRACT__

class Base1{
public:
	virtual void display() const =0;//纯虚函数
};

class Base2:public Base1{
public:
	void display() const;//覆盖基类的构造函数
};


class Derived:public Base2{
public:
	void display() const;//覆盖基类的构造函数
};

void fun(Base1 *ptr);


#endif