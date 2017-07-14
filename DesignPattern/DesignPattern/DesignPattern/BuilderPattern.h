#ifndef __BUILDER_H__
#define __BUILDER_H__
#include <string>
#include <iostream>
#include <vector>

//Product Class 产品类，有多个部件组成
class Product{
private:
	std::vector<std::string> parts;

public:
	//添加产品组件
	void add(std::string part){
		parts.push_back(part);
	}

	//列举所有的产品组件
	void show(){
		std::cout<<"产品 创建————————"<<std::endl;
		std::vector<std::string>::iterator it;
		for(it=parts.begin();it!=parts.end();it++){
			std::cout<<*it<<std::endl;
		}
	}
};

//抽象建造者
class Builder{
public:
	virtual void buildPartA()=0;
	virtual void buildPartB()=0;
	virtual Product *getResult()=0;
};

//ConcreteBulider1 具体建造者类
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
		product->add("部件A");
	};

	void buildPartB(){
		product->add("部件B");
	}

	Product *getResult(){
		return product;
	}
};

//ConcreteBulider2 具体建造者类
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
		product->add("部件X");
	};

	void buildPartB(){
		product->add("部件Y");
	}

	Product *getResult(){
		return product;
	}
};



//Director Class，指挥者类。  
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