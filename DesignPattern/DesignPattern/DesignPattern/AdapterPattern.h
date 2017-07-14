#ifndef _ADAPTER_H_  
#define _ADAPTER_H_    

#include <string>  
#include <iostream>  

//Target,�˴�Ϊ�˶�Ա,�û������Ľӿ�  
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

//Adaptee���˴�Ϊ�⼮�з�ForeignCenter�����Ľӿں�Target�Ľӿڲ�һ������Ҫ���루Adapter������æת�������䣩  
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
		std::cout<<"�⼮�з�  "<<name<<"  ����"<<std::endl;  
	}  

	void ForeignDefense()  
	{  
		std::cout<<"�⼮�з�  "<<name<<"  ����"<<std::endl;  
	}  
};  

//Adapter,�˴�Ϊ����  
class Translator:public Player  
{  
private:  
	ForeignCenter* wjzf; //��ForeignCenter���а�װ��ת����Target����Player�������Ľӿ� 

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
	//���������һ���װ��ʹ����ʽ��Target��Ľӿ�һ�� 
	void Attack()  
	{  
		wjzf->ForeignAttack();  
	}  

	void Defense()  
	{  
		wjzf->ForeignDefense();  
	}  
};  


//��������ͨ�Ľӿں�Target�ӿ�һ����3�����࣬����ҪҪ����  

//ǰ��  
class Forwards:public Player  
{  
public:  
	Forwards(std::string name):Player(name){}  

	void Attack()  
	{  
		std::cout<<"ǰ��  "<<name<<"  ����"<<std::endl;  
	}  

	void Defense()  
	{  
		std::cout<<"ǰ��  "<<name<<"  ����"<<std::endl;  
	}  
};  

//�з�  
class Center:public Player  
{  
public:  
	Center(std::string name):Player(name){}  

	void Attack()  
	{  
		std::cout<<"�з�  "<<name<<"  ����"<<std::endl;  
	}  

	void Defense()  
	{  
		std::cout<<"�з�  "<<name<<"  ����"<<std::endl;  
	}  
};  

//����  
class Guards:public Player  
{  
public:  
	Guards(std::string name):Player(name){}  

	void Attack()  
	{  
		std::cout<<"����  "<<name<<"  ����"<<std::endl;  
	}  

	void Defense()  
	{  
		std::cout<<"����  "<<name<<"  ����"<<std::endl;  
	}  
};  
#endif  
