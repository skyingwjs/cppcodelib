#ifndef __BUILDER_H__
#define __BUILDER_H__
#include <string>
#include <iostream>
#include <vector>

//Product Class ��Ʒ�࣬�ж���������
class Product{
private:
	std::vector<std::string> parts;

public:
	//��Ӳ�Ʒ���
	void add(std::string part){
		parts.push_back(part);
	}

	//�о����еĲ�Ʒ���
	void show(){
		std::cout<<"��Ʒ ��������������������"<<std::endl;
		std::vector<std::string>::iterator it;
		for(it=parts.begin();it!=parts.end();it++){
			std::cout<<*it<<std::endl;
		}
	}
};

//��������
class Builder{
public:
	virtual void buildPartA()=0;
	virtual void buildPartB()=0;
	virtual Product *getResult()=0;
};

//ConcreteBulider1 ���彨������
class ConcreteBuilder1:public Builder{
private :
	Product *product;

public:
	ConcreteBuilder1(){
		product=new Product();
	}
	~ConcreteBuilder1(){
		delete product;
	}

	void buildPartA(){
		product->add("����A");
	};

	void buildPartB(){
		product->add("����B");
	}

	Product *getResult(){
		return product;
	}
};

//ConcreteBulider2 ���彨������
class ConcreteBuilder2:public Builder{
private :
	Product *product;

public:
	ConcreteBuilder2(){
		product=new Product();
	}
	~ConcreteBuilder2(){
		delete product;
	}

	void buildPartA(){
		product->add("����X");
	};

	void buildPartB(){
		product->add("����Y");
	}

	Product *getResult(){
		return product;
	}
};



//Director Class��ָ�����ࡣ  
class Director  
{  
public:  
	void construct(Builder* builder)  
	{  
		builder->buildPartA();  
		builder->buildPartB();  
	}  

}; 
#endif