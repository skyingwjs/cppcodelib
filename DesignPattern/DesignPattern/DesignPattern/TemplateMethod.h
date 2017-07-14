#ifndef __TESTPAPER_H__
#define __TESTPAPER_H__
#include <iostream>
#include <string>

//AbstractClass ʵ����һ��ģ��  ������һ���㷨�Ǽ� ��ɹǼܵľ��岽�����������ʵ��
class TestPaper{
public:
	void testQuestion1(){
		std::cout<<"����õ����������˹������������콣�������������������ǡ���a.��ĥ���� b.����� c.���ٺϽ�� d.̼����ά"<<std::endl;  
		std::cout<<"�𰸣�"<<answer1()<<std::endl; 
	}
	void testQuestion2(){
		std::cout<<"�������Ӣ��½��˫�������黨����ɡ���a.ʹ����ֲ�ﲻ�ٺ��� b.ʹһ����ϡ������� c.�ƻ����Ǹ�����Ȧ����̬ƽ�� d.��ɸõ���ɳĮ��"<<std::endl;  
		std::cout<<"�𰸣�"<<answer2()<<std::endl;  
	}

	void testQuestion3(){
		std::cout<<"�������ʹ��ɽʦͽ���ҹ�����Ż�²�ֹ��������Ǵ�򣬻�����ǿ�ʲôҩ����a.��˾ƥ�� b.ţ�ƽⶾƬ c.������ d.�����Ǻȴ���ţ��"<<std::endl;  
		std::cout<<"�𰸣�"<<answer3()<<std::endl;  
	}

protected:
	virtual std::string answer1(){
		return "";
	}

	virtual std::string answer2(){
		return "";
	}

	virtual std::string answer3(){
		return "";
	}
};

//ConcreteClass ʵ�־��岽��
class TestPaperA:public TestPaper{
protected:
	virtual std::string answer1(){
		return "b";
	}

	virtual std::string answer2(){
		return "c";
	}

	virtual std::string answer3(){
		return "a";
	}

};

//ConcreteClass ʵ�־��岽��
class TestPaperB:public TestPaper{
protected:
	virtual std::string answer1(){
		return "c";
	}

	virtual std::string answer2(){
		return "a";
	}

	virtual std::string answer3(){
		return "b";
	}

};


#endif