#ifndef __TESTPAPER_H__
#define __TESTPAPER_H__
#include <iostream>
#include <string>

//AbstractClass 实现了一个模板  定义了一个算法骨架 组成骨架的具体步骤放在子类中实现
class TestPaper{
public:
	void testQuestion1(){
		std::cout<<"杨过得到，后来给了郭靖，练成倚天剑、屠龙刀的玄铁可能是【】a.球磨铸铁 b.马口铁 c.高速合金钢 d.碳素纤维"<<std::endl;  
		std::cout<<"答案："<<answer1()<<std::endl; 
	}
	void testQuestion2(){
		std::cout<<"杨过、程英、陆无双铲除了情花，造成【】a.使这种植物不再害人 b.使一种珍稀物种灭绝 c.破坏了那个生物圈的生态平衡 d.造成该地区沙漠化"<<std::endl;  
		std::cout<<"答案："<<answer2()<<std::endl;  
	}

	void testQuestion3(){
		std::cout<<"蓝凤凰致使华山师徒、桃谷六仙呕吐不止，如果你是大夫，会给他们开什么药【】a.阿司匹林 b.牛黄解毒片 c.氟哌酸 d.让他们喝大量牛奶"<<std::endl;  
		std::cout<<"答案："<<answer3()<<std::endl;  
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

//ConcreteClass 实现具体步骤
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

//ConcreteClass 实现具体步骤
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