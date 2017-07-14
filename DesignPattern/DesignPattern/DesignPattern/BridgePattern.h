#ifndef _BRIDGE_PATTERN_H_
#define _BRIDGE_PATTERN_H_

#include <iostream>
#include <string>
//Implementor���˴�Ϊ�ֻ����������  
class HandsetSoft{
public:
	virtual void Run()=0;
};
//ConcreteImplementorA���˴�Ϊ�ֻ���Ϸ  
class HandsetGame:public HandsetSoft{
	void Run(){
		std::cout<<"�����ֻ���Ϸ"<<endl;
	}
};

//ConcreteImplementorB���˴�Ϊ�ֻ�ͨѶ¼  
class HandsetAddressList:public HandsetSoft{
	void Run(){
		std::cout<<"�����ֻ�ͨѶ¼"<<endl;
	}
};
//Abstraction���˴�Ϊ�ֻ�Ʒ�Ƴ�����  
class HandsetBrand{
protected:
	HandsetSoft *soft;
public:
	void SetHandsetSoft(HandsetSoft *soft){
		this->soft=soft;
	}

	virtual void Run()=0;
};

//RefineAbstraction���˴�Ϊ�ֻ�ƷN  
class HandsetBrandN:public HandsetBrand{
public:
	void Run(){
		soft->Run();
	}
};
//RefineAbstraction���˴�Ϊ�ֻ�ƷM  
class HandsetBrandM:public HandsetBrand{
public:
	void Run(){
		soft->Run();
	}
};
#endif