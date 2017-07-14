#include <iostream>
#include "abstract.h"
using namespace std;


void Base2::display() const {
	cout<<"Baae2::display()"<<endl;
}


void Derived::display() const{
	cout<<"Derived::display()"<<endl;
}

void fun(Base1 *ptr){
	ptr->display();
}