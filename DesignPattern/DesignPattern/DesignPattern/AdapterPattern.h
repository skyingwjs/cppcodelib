#ifndef _ADAPTER_H_  
#define _ADAPTER_H_    

#include <string>  
#include <iostream>  

//Target,此处为运动员,用户期望的接口  
class Player  
{  
protected:  
	std::string name;  
public:  
	Player(std::string name)  
	{  
		this->name=name;  
	}  
	virtual void Attack()=0;  
	virtual void Defense()=0;  
};  

//Adaptee，此处为外籍中锋ForeignCenter，它的接口和Target的接口不一样，需要翻译（Adapter）来帮忙转换（适配）  
class ForeignCenter  
{  
private:  
	std::string name;  
public:  
	void SetName(std::string name)  
	{  
		this->name=name;  
	}  
	std::string GetName()  
	{  
		return name;  
	}  
	void ForeignAttack()  
	{  
		std::cout<<"外籍中锋  "<<name<<"  进攻"<<std::endl;  
	}  

	void ForeignDefense()  
	{  
		std::cout<<"外籍中锋  "<<name<<"  防守"<<std::endl;  
	}  
};  

//Adapter,此处为翻译  
class Translator:public Player  
{  
private:  
	ForeignCenter* wjzf; //对ForeignCenter进行包装，转换成Target（即Player）期望的接口 

public:  
	Translator(std::string name):Player(name)  
	{  
		wjzf=new ForeignCenter;  
		wjzf->SetName(name);  
	}  
	~Translator()  
	{  
		delete wjzf;  
	}  
	//在外层再做一层封装，使其形式跟Target类的接口一样 
	void Attack()  
	{  
		wjzf->ForeignAttack();  
	}  

	void Defense()  
	{  
		wjzf->ForeignDefense();  
	}  
};  


//下面是普通的接口和Target接口一样的3个子类，不需要要翻译  

//前锋  
class Forwards:public Player  
{  
public:  
	Forwards(std::string name):Player(name){}  

	void Attack()  
	{  
		std::cout<<"前锋  "<<name<<"  进攻"<<std::endl;  
	}  

	void Defense()  
	{  
		std::cout<<"前锋  "<<name<<"  防守"<<std::endl;  
	}  
};  

//中锋  
class Center:public Player  
{  
public:  
	Center(std::string name):Player(name){}  

	void Attack()  
	{  
		std::cout<<"中锋  "<<name<<"  进攻"<<std::endl;  
	}  

	void Defense()  
	{  
		std::cout<<"中锋  "<<name<<"  防守"<<std::endl;  
	}  
};  

//后卫  
class Guards:public Player  
{  
public:  
	Guards(std::string name):Player(name){}  

	void Attack()  
	{  
		std::cout<<"后卫  "<<name<<"  进攻"<<std::endl;  
	}  

	void Defense()  
	{  
		std::cout<<"后卫  "<<name<<"  防守"<<std::endl;  
	}  
};  
#endif  
