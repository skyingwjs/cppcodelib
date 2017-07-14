#ifndef _COMMAND_PARTTERN_H_
#define _COMMAND_PARTTERN_H_

#include <iostream>  
#include <string>  
#include <vector>  
#include <ctime>  

//Receiver �˴�Ϊ�����⴮��
class Barbecuer{
public:
	void BakeMutton(){
		 std::cout<<"�����⴮��"<<std::endl;
	}

	void BakeChickenWing(){
		std::cout<<"�����ᣡ"<<endl;
	}
};

//Command ����������
class Command{
protected:
	Barbecuer *receiver;

public:
	Command(Barbecuer *receiver){
		this->receiver=receiver;
	}

	virtual void ExcuteCommand()=0;
};

//ConcreteCommand�࣬��������  
class BakeMuttonCommand:public Command{
public:
	BakeMuttonCommand(Barbecuer *receiver):Command(receiver){

	}

	void ExcuteCommand(){
		receiver->BakeMutton();
	}
};

//ConcreteCommand�࣬��������  
class BakeChickenWingCommand:public Command  
{  
public:  
	BakeChickenWingCommand(Barbecuer* receiver):Command(receiver){}  
	void ExcuteCommand()  
	{  
		receiver->BakeChickenWing();  
	}  

};  

//Invoker �˴�Ϊ����Ա
class Waiter{
private:
	std::vector<Command *> *orders;

public:
	Waiter(){
		orders=new std::vector<Command *>;
	}

	~Waiter(){
		delete orders;
	}

	//���ö���
	void SetOrder(Command * command){
		//�ж���������Ͳ��ֱ�����ͬ�Ĵ���  
		if(typeid(*command)==typeid(BakeChickenWingCommand))  
		{  
			std::cout<<"��־������Ա������û���ˣ�������տ���"<<std::endl;  
		}  
		else if(typeid(*command)==typeid(BakeMuttonCommand))  
		{  
			orders->push_back(command);  

			time_t now=time(0);  
			std::cout<<"��־�����Ӷ���������ģʽ.�����⴮  "<<"ʱ�䣺"<<asctime(gmtime(&now));  
		}  
		else  
		{  
			std::cout<<"��־����ʱû�и÷���"<<std::endl;  
		}  

	}

	//֪ͨȫ��ִ��
	void Notify()  
	{  
		std::vector<Command*>::iterator it;  
		for(it=orders->begin();it!=orders->end();it++)  
		{  
			(*it)->ExcuteCommand();  
		}  

	} 
};

#endif