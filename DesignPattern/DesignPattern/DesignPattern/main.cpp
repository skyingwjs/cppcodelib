#include <iostream>
#include <cstdlib>
#include <string>

#include "SimpleFactory.h"
#include "StrategyPattern.h"
#include "DecoratorPattern.h"  
#include "ProxyPattern.h"
#include "FactoryMethod.h"
#include "PrototypePattern.h"
#include "TemplateMethod.h"
#include "FacedePattern.h"
#include "BuilderPattern.h"
#include "Observer.h"
#include "Subject.h"
#include "AbstractFactory.h"
#include "Work.h"
#include "AdapterPattern.h"
#include "MementoPattern.h"
#include "CompositePattern.h"
#include "Aggregate.h"
#include "Iterator.h"
#include "BridgePattern.h"
#include "CommandPattern.h"
#include "ChainOfResponsibility.h"
#include "Country.h"
#include "UnitedNations.h"
using namespace std;

int main(){

	/*SimpleFactory*/
	//OperationFactory of;
	//Operation *operation=of.createOperation('/');
	//operation->setA(1.2);
	//operation->setB(0.3);
	//cout<<operation->getResult()<<endl;
	//if(operation){
	//	delete operation;
	//	operation=NULL;
	//}


	/*StrategyPattern*/
	//double total=0;
	//double totalPrices=0;
	////正常收费
	//CashContext* cc1=NULL;
	//cc1=new CashContext(1);
	//totalPrices=cc1->getResult(300);
	//total+=totalPrices;
	//cout<<"Type: 正常收费 totalPices:"<<totalPrices<<" total: "<<total<<endl;
	//totalPrices=0;

	////返现类型
	//CashContext* cc2=NULL;
	//cc2=new CashContext(2);
	//totalPrices=cc2->getResult(700);
	//total+=totalPrices;
	//cout<<"Type: 正常收费 totalPices:"<<totalPrices<<" total: "<<total<<endl;
	//totalPrices=0;

	////打折
	//CashContext* cc3=NULL;
	//cc3=new CashContext(3);
	//totalPrices=cc3->getResult(300);
	//total+=totalPrices;
	//cout<<"Type: 正常收费 totalPices:"<<totalPrices<<" total: "<<total<<endl;
	//totalPrices=0;

	/*DecoratorPattern*/
	/*Person* xc=NULL;  
	xc=new Person("小菜");  

	std::cout<<"第一种装扮："<<std::endl;  

	Sneakers* pqx=NULL;  
	pqx=new Sneakers();  
	BigTrouser* kk=NULL;  
	kk=new BigTrouser();  
	TShirts* dtx=NULL;  
	dtx=new TShirts();  

	pqx->Decorator(xc);  
	kk->Decorator(pqx);  
	dtx->Decorator(kk);  

	dtx->Show();  

	std::cout<<"第二种装扮："<<std::endl;  

	LeatherShoes* px=NULL;  
	px=new LeatherShoes();  
	Tie* ld=NULL;  
	ld=new Tie();  
	Suit* xz=NULL;  
	xz=new Suit();  

	px->Decorator(xc);  
	ld->Decorator(px);  
	xz->Decorator(ld);  

	xz->Show();  

	if(xc!=NULL)  
	{  
		delete xc;  
		xc=NULL;  
	}  
	if(pqx!=NULL)  
	{  
		delete pqx;  
		pqx=NULL;  
	}  
	if(kk!=NULL)  
	{  
		delete kk;  
		kk=NULL;  
	}  
	if(dtx!=NULL)  
	{  
		delete dtx;  
		dtx=NULL;  
	}  
	if(px!=NULL)  
	{  
		delete px;  
		px=NULL;  
	}  
	if(ld!=NULL)  
	{  
		delete ld;  
		ld=NULL;  
	}  
	if(xz!=NULL)  
	{  
		delete xz;  
		xz=NULL;  
	}  */

	/*代理模式*/
	/*SchoolGril *jiaojiao=new SchoolGril();
	jiaojiao->setName("娇娇");

	Proxy *daili=new Proxy(jiaojiao);

	daili->giveDolls();
	daili->giveFlowers();
	daili->giveChocolate();

	delete jiaojiao;
	jiaojiao=NULL;
	delete daili;
	daili=NULL;*/

	/*工厂方法模式*/
	//AbstractFactory *af=NULL;
	//af=new AddFactory();
	//
	//Operation* oper=NULL;
	//oper=af->createOperation();
	//
	//oper->setA(1);
	//oper->setB(2);
	//cout<<oper->getResult()<<endl;
	//
	//if(af!=NULL){
	//delete af;
	//af=NULL;
	//}
	//
	//if(oper!=NULL){
	//delete oper;
	//oper=NULL;
	//}
	
	/*原型模式  简历复印*/
	//Resume *a=new Resume("大鸟");
	//a->setPersonalInfo("男","29");
	//a->setWorkExperience("1998-2000","xx公司");

	//Resume *b=a->clone();
	//b->setWorkExperience("1998-2006","yy公司");

	//Resume* c=b->clone();  
	//c->setPersonalInfo("男","24");  
	//c->setWorkExperience("1998-2003","ZZ公司");  

	//a->display();  
	//b->display();  
	//c->display();  

	//delete a;  
	//delete b;  
	//delete c;  
	//a=b=c=NULL; 

	/*模板方法模式*/
	//std::cout<<"学生甲抄的试卷："<<std::endl;  
	//TestPaper* studentA=new TestPaperA();  
	//studentA->testQuestion1();  
	//studentA->testQuestion2();  
	//studentA->testQuestion3();  
	//std::cout<<std::endl;  

	//std::cout<<"学生乙抄的试卷："<<std::endl;  
	//TestPaper* studentB=new TestPaperB();  
	//studentB->testQuestion1();  
	//studentB->testQuestion2();  
	//studentB->testQuestion3();  
	//std::cout<<std::endl;  

	//delete studentA;  
	//delete studentB;  
	
	/*外观模式*/
	//Facade* facade=new Facade();  
	//facade->MethodA();  
	//facade->MethodB();  
	//delete facade;  
	
	/*建造者模式*/
	//Director *director=new Director();
	//Builder *builder1=new ConcreteBuilder1();
	//Builder *builder2=new ConcreteBuilder2();

	//std::cout<<"指挥者用ConcreteBuilder1的方法建造产品："<<std::endl;  
	//director->construct(builder1);
	//Product *p1=builder1->getResult();
	//p1->show();
	//std::cout<<std::endl;

	//std::cout<<"指挥者用ConcreteBuilder2的方法建造产品："<<std::endl;  
	//director->construct(builder2);
	//Product *p2=builder2->getResult();
	//p2->show();
	//std::cout<<std::endl;


	//delete builder1;
	//delete builder2;
	//delete director;

	/*观察者模式*/
	//通知者  
	//Subject* huhansan=new Boss();  

	////4个观察者实例  
	//Observer* tongshi1=new StockObserver("魏关姹",huhansan);  
	//Observer* tongshi2=new StockObserver("易管察",huhansan);  
	//Observer* tongshi3=new NBAObserver("霍华德",huhansan);  
	//Observer* tongshi4=new NBAObserver("林书豪",huhansan);  

	////将4个观察者都加入到通知者的通知队列中  
	//huhansan->attach(tongshi1);  
	//huhansan->attach(tongshi2);  
	//huhansan->attach(tongshi3);  
	//huhansan->attach(tongshi4);  

	////魏关姹没有被老板通知到，减去。  
	//huhansan->detach(tongshi1);  

	//huhansan->setSubjectState("我胡汉三回来了！");  

	////通知  
	//huhansan->notify();  

	//delete huhansan;  
	//delete tongshi1;  
	//delete tongshi2;  
	//delete tongshi3;  
	//delete tongshi4;  
    
	/*抽象工厂模式*/
	//User user;
	//Department department;

	////ConcreteFactory1
	//IFactory* factory=new SqlserverFactory;

	////ProductA1
	//IUser* iu=NULL;  
	//iu=factory->CreateUser();  
	//iu->Insert(user);  
	//iu->GetUser(1);  

	////ProductB1  
	//IDepartment* id=NULL;  
	//id=factory->CreateDepartment();  
	//id->Insert(department);  
	//id->GetDepartment(1);  

	//if(factory!=NULL)  
	//{  
	//	delete factory;  
	//	factory=NULL;  
	//}  
	//if(iu!=NULL)  
	//{  
	//	delete iu;  
	//	iu=NULL;  
	//}  
	//if(id!=NULL)  
	//{  
	//	delete id;  
	//	id=NULL;  
	//}  

	/*状态模式*/
	/*Work emergencyProjects;  

	emergencyProjects.setHour(9);  
	emergencyProjects.writeProgram();  

	emergencyProjects.setHour(10);  
	emergencyProjects.writeProgram();  

	emergencyProjects.setHour(12);  
	emergencyProjects.writeProgram();  

	emergencyProjects.setHour(13);  
	emergencyProjects.writeProgram();  

	emergencyProjects.setHour(14);  
	emergencyProjects.writeProgram();  

	emergencyProjects.setHour(17);  
	emergencyProjects.writeProgram();  

	emergencyProjects.setFinish(false);  

	emergencyProjects.setHour(19);  
	emergencyProjects.writeProgram();  

	emergencyProjects.setHour(22);  
	emergencyProjects.writeProgram();  */
	
	/*适配器模式*/
	
	//Player* b=new Forwards("巴蒂尔");  
	//b->Attack();  

	//Player* m=new Guards("麦克格雷迪");  
	//m->Attack();  

	////翻译告诉姚明，教练让你既要进攻，又要防守  
	//Player* ym=new Translator("姚明");  
	//ym->Attack();  
	//ym->Defense();  

	//delete b;  
	//delete m;  
	//delete ym;  
	
	/*备忘录模式*/
	//大战boss前
	//GameRole* lixiaoyao=new GameRole();
	//lixiaoyao->GetInitState();
	//lixiaoyao->StateDisplay();

	////保持进度
	//RoleStateCaretaker *stateAdmin=new RoleStateCaretaker();
	//stateAdmin->SetMemento(lixiaoyao->SaveState());

	////大战boss时 损耗严重
	//lixiaoyao->Fight();
	//lixiaoyao->StateDisplay();

	////恢复之前状态
	//lixiaoyao->RocoveryState(*stateAdmin->GetMomento());
	//lixiaoyao->StateDisplay();

	//delete lixiaoyao;
	//delete stateAdmin;

	/*组合模式*/
	//Company* root=new ConcreteCompany("北京总公司");  
	//root->Add(new HRDepartment("总公司人力资源部"));  
	//root->Add(new FinanceDepartment("总公司财务处"));  

	//Company* comp=new ConcreteCompany("上海华东分公司");  
	//comp->Add(new HRDepartment("华东分公司人力资源部"));  
	//comp->Add(new FinanceDepartment("华东分公司财务处"));  

	//root->Add(comp);  

	//Company* comp1=new ConcreteCompany("南京办事处");  
	//comp1->Add(new HRDepartment("南京办事处人力资源部"));  
	//comp1->Add(new FinanceDepartment("南京办事处财务处"));  

	//comp->Add(comp1);  

	//Company* comp2=new ConcreteCompany("杭州办事处");  
	//comp2->Add(new HRDepartment("杭州办事处人力资源部"));  
	//comp2->Add(new FinanceDepartment("杭州办事处财务处"));  

	//comp->Add(comp2);  

	//std::cout<<"结构图："<<std::endl<<std::endl;  
	//root->Display(1);  

	//std::cout<<std::endl<<"职责："<<std::endl<<std::endl;  
	//root->LineOfDuty();  

	//delete root;  

	/*迭代器模式*/
	////公交车，即聚集对象  
	//ConcreteAggregate* a=new ConcreteAggregate();  

	////新上来的乘客  
	//a->GetVector()->push_back("大鸟");  
	//a->GetVector()->push_back("小菜");  
	//a->GetVector()->push_back("行李");  
	//a->GetVector()->push_back("老外");  
	//a->GetVector()->push_back("公交内部人员");  
	//a->GetVector()->push_back("小偷");  

	////售票员出场，先看好了上车的是哪些人，即声明了迭代器对象。  
	////下面两种获取迭代器的方法都可以  
	////Iterator* i=new ConcreteIterator(a);  

	////产生从前往后的迭代器  
	//Iterator* it1=a->CreateIterator();  

	////告知每一位乘客买票  
	//std::cout<<"从前往后的迭代器："<<std::endl<<std::endl;  
	//while(!it1->IsDone())  
	//{  
	//	std::cout<<it1->CurrentItem()<<"  请买车票！"<<std::endl;  
	//	it1->Next();  
	//}  
	//std::cout<<std::endl;  

	////产生从后往前的迭代器  
	//Iterator* it2=a->CreateIteratorDesc();  

	////告知每一位乘客买票  
	//std::cout<<"从后往前的迭代器："<<std::endl<<std::endl;  
	//while(!it2->IsDone())  
	//{  
	//	std::cout<<it2->CurrentItem()<<"  请买车票！"<<std::endl;  
	//	it2->Next();  
	//}  
	//std::cout<<std::endl<<std::endl;  

	//delete a,it1,it2;  
	
	/*桥接模式*/
	////手机品牌N
	//std::cout<<"手机品牌N："<<std::endl;  
	//HandsetBrand* ab=new HandsetBrandN();  
	//ab->SetHandsetSoft(new HandsetGame());  
	//ab->Run(); 

	//ab->SetHandsetSoft(new HandsetAddressList());  
	//ab->Run();  

	//delete ab;  

	////手机品牌M  
	//std::cout<<std::endl<<"手机品牌M："<<std::endl;  
	//ab=new HandsetBrandM();  

	//ab->SetHandsetSoft(new HandsetGame());  
	//ab->Run();  

	//ab->SetHandsetSoft(new HandsetAddressList());  
	//ab->Run();  

	//delete ab;  
	//ab=NULL;  
	
	
	/*命令模式*/      //开店前的准备  
	//Barbecuer* boy=new Barbecuer();  

	//Command* bakeMuttonCommand1=new BakeMuttonCommand(boy);  
	//Command* bakeMuttonCommand2=new BakeMuttonCommand(boy);  
	//Command* bakeChickenWingCommand1=new BakeChickenWingCommand(boy);  

	//Waiter* girl=new Waiter();  

	////开门营业，顾客点菜  
	//girl->SetOrder(bakeMuttonCommand1);  
	//girl->SetOrder(bakeMuttonCommand2);  
	//girl->SetOrder(bakeChickenWingCommand1);  

	////点菜完毕，通知厨房  
	//girl->Notify();  

	//delete boy,bakeMuttonCommand1,bakeMuttonCommand2,bakeChickenWingCommand1;  
	
	/*责任链模式*/
    //Manager *jinli=new CommonManager("经理");
	//Manager *zongjian=new Majordomo("总监");
	//Manager *zongjinli=new GeneralManager("总经理");

	////设置上级  按实际情况进行更改
	//jinli->SetSuperior(zongjian);
	//zongjian->SetSuperior(zongjinli);

	////下面是4个请求  
	////请求1：请假1天  
	//Request request1;  
	//request1.SetType("请假");  
	//request1.SetContent("小菜请假");  
	//request1.SetNumber(1);  
	////客户端的申请都是由“经理”发起，但实际谁来决策由具体管理类来处理，客户端不知道  
	//jinli->RequestApplication(&request1);  

	////请求2：请假4天  
	//Request request2;  
	//request2.SetType("请假");  
	//request2.SetContent("小菜请假");  
	//request2.SetNumber(4);  
	////客户端的申请都是由“经理”发起，但实际谁来决策由具体管理类来处理，客户端不知道  
	//jinli->RequestApplication(&request2);  

	////请求3：加薪500元  
	//Request request3;  
	//request3.SetType("加薪");  
	//request3.SetContent("小菜请求加薪");  
	//request3.SetNumber(500);  
	////客户端的申请都是由“经理”发起，但实际谁来决策由具体管理类来处理，客户端不知道  
	//jinli->RequestApplication(&request3);  

	////请求4：加薪1000元  
	//Request request4;  
	//request4.SetType("加薪");  
	//request4.SetContent("小菜请求加薪");  
	//request4.SetNumber(1000);  
	////客户端的申请都是由“经理”发起，但实际谁来决策由具体管理类来处理，客户端不知道  
	//jinli->RequestApplication(&request4);  

	//delete jinli,zongjian,zongjinli;  
	
	/*中介者模式*/
	UnitedNationsSecurityCouncil *un=new UnitedNationsSecurityCouncil();
	Country *usa=new USA(un);
	Country *iraq=new Iraq(un);

	un->SetColleague1(usa);
	un->SetColleague2(iraq);

	usa->Declare("不准研发核武器");
	iraq->Declare("我们没有研发核武器");

	system("pause");
	return 0;
}
