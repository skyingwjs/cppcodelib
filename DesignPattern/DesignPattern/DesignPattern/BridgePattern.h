#ifndef _BRIDGE_PATTERN_H_
#define _BRIDGE_PATTERN_H_

#include <iostream>
#include <string>
//Implementor：此处为手机软件抽象类  
class HandsetSoft{
public:
	virtual void Run()=0;
};
//ConcreteImplementorA，此处为手机游戏  
class HandsetGame:public HandsetSoft{
	void Run(){
		std::cout<<"运行手机游戏"<<endl;
	}
};

//ConcreteImplementorB，此处为手机通讯录  
class HandsetAddressList:public HandsetSoft{
	void Run(){
		std::cout<<"运行手机通讯录"<<endl;
	}
};
//Abstraction，此处为手机品牌抽象类  
class HandsetBrand{
protected:
	HandsetSoft *soft;
public:
	void SetHandsetSoft(HandsetSoft *soft){
		this->soft=soft;
	}

	virtual void Run()=0;
};

//RefineAbstraction，此处为手机品N  
class HandsetBrandN:public HandsetBrand{
public:
	void Run(){
		soft->Run();
	}
};
//RefineAbstraction，此处为手机品M  
class HandsetBrandM:public HandsetBrand{
public:
	void Run(){
		soft->Run();
	}
};
#endif