#include "vld.h"  
#include <iostream>  

using namespace std;  

void fun()  
{  
	char* tmp = new char[10];  
	memset(tmp, 0, 10);  
}  

int main(int argc, char* argv[])  
{  
	fun();  

	cout<<"ok!"<<endl;  

	return 0;  
}  