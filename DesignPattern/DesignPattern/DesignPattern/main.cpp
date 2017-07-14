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
	////�����շ�
	//CashContext* cc1=NULL;
	//cc1=new CashContext(1);
	//totalPrices=cc1->getResult(300);
	//total+=totalPrices;
	//cout<<"Type: �����շ� totalPices:"<<totalPrices<<" total: "<<total<<endl;
	//totalPrices=0;

	////��������
	//CashContext* cc2=NULL;
	//cc2=new CashContext(2);
	//totalPrices=cc2->getResult(700);
	//total+=totalPrices;
	//cout<<"Type: �����շ� totalPices:"<<totalPrices<<" total: "<<total<<endl;
	//totalPrices=0;

	////����
	//CashContext* cc3=NULL;
	//cc3=new CashContext(3);
	//totalPrices=cc3->getResult(300);
	//total+=totalPrices;
	//cout<<"Type: �����շ� totalPices:"<<totalPrices<<" total: "<<total<<endl;
	//totalPrices=0;

	/*DecoratorPattern*/
	/*Person* xc=NULL;  
	xc=new Person("С��");  

	std::cout<<"��һ��װ�磺"<<std::endl;  

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

	std::cout<<"�ڶ���װ�磺"<<std::endl;  

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

	/*����ģʽ*/
	/*SchoolGril *jiaojiao=new SchoolGril();
	jiaojiao->setName("����");

	Proxy *daili=new Proxy(jiaojiao);

	daili->giveDolls();
	daili->giveFlowers();
	daili->giveChocolate();

	delete jiaojiao;
	jiaojiao=NULL;
	delete daili;
	daili=NULL;*/

	/*��������ģʽ*/
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
	
	/*ԭ��ģʽ  ������ӡ*/
	//Resume *a=new Resume("����");
	//a->setPersonalInfo("��","29");
	//a->setWorkExperience("1998-2000","xx��˾");

	//Resume *b=a->clone();
	//b->setWorkExperience("1998-2006","yy��˾");

	//Resume* c=b->clone();  
	//c->setPersonalInfo("��","24");  
	//c->setWorkExperience("1998-2003","ZZ��˾");  

	//a->display();  
	//b->display();  
	//c->display();  

	//delete a;  
	//delete b;  
	//delete c;  
	//a=b=c=NULL; 

	/*ģ�巽��ģʽ*/
	//std::cout<<"ѧ���׳����Ծ�"<<std::endl;  
	//TestPaper* studentA=new TestPaperA();  
	//studentA->testQuestion1();  
	//studentA->testQuestion2();  
	//studentA->testQuestion3();  
	//std::cout<<std::endl;  

	//std::cout<<"ѧ���ҳ����Ծ�"<<std::endl;  
	//TestPaper* studentB=new TestPaperB();  
	//studentB->testQuestion1();  
	//studentB->testQuestion2();  
	//studentB->testQuestion3();  
	//std::cout<<std::endl;  

	//delete studentA;  
	//delete studentB;  
	
	/*���ģʽ*/
	//Facade* facade=new Facade();  
	//facade->MethodA();  
	//facade->MethodB();  
	//delete facade;  
	
	/*������ģʽ*/
	//Director *director=new Director();
	//Builder *builder1=new ConcreteBuilder1();
	//Builder *builder2=new ConcreteBuilder2();

	//std::cout<<"ָ������ConcreteBuilder1�ķ��������Ʒ��"<<std::endl;  
	//director->construct(builder1);
	//Product *p1=builder1->getResult();
	//p1->show();
	//std::cout<<std::endl;

	//std::cout<<"ָ������ConcreteBuilder2�ķ��������Ʒ��"<<std::endl;  
	//director->construct(builder2);
	//Product *p2=builder2->getResult();
	//p2->show();
	//std::cout<<std::endl;


	//delete builder1;
	//delete builder2;
	//delete director;

	/*�۲���ģʽ*/
	//֪ͨ��  
	//Subject* huhansan=new Boss();  

	////4���۲���ʵ��  
	//Observer* tongshi1=new StockObserver("κ���",huhansan);  
	//Observer* tongshi2=new StockObserver("�׹ܲ�",huhansan);  
	//Observer* tongshi3=new NBAObserver("������",huhansan);  
	//Observer* tongshi4=new NBAObserver("�����",huhansan);  

	////��4���۲��߶����뵽֪ͨ�ߵ�֪ͨ������  
	//huhansan->attach(tongshi1);  
	//huhansan->attach(tongshi2);  
	//huhansan->attach(tongshi3);  
	//huhansan->attach(tongshi4);  

	////κ���û�б��ϰ�֪ͨ������ȥ��  
	//huhansan->detach(tongshi1);  

	//huhansan->setSubjectState("�Һ����������ˣ�");  

	////֪ͨ  
	//huhansan->notify();  

	//delete huhansan;  
	//delete tongshi1;  
	//delete tongshi2;  
	//delete tongshi3;  
	//delete tongshi4;  
    
	/*���󹤳�ģʽ*/
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

	/*״̬ģʽ*/
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
	
	/*������ģʽ*/
	
	//Player* b=new Forwards("�͵ٶ�");  
	//b->Attack();  

	//Player* m=new Guards("��˸��׵�");  
	//m->Attack();  

	////�������Ҧ�������������Ҫ��������Ҫ����  
	//Player* ym=new Translator("Ҧ��");  
	//ym->Attack();  
	//ym->Defense();  

	//delete b;  
	//delete m;  
	//delete ym;  
	
	/*����¼ģʽ*/
	//��սbossǰ
	//GameRole* lixiaoyao=new GameRole();
	//lixiaoyao->GetInitState();
	//lixiaoyao->StateDisplay();

	////���ֽ���
	//RoleStateCaretaker *stateAdmin=new RoleStateCaretaker();
	//stateAdmin->SetMemento(lixiaoyao->SaveState());

	////��սbossʱ �������
	//lixiaoyao->Fight();
	//lixiaoyao->StateDisplay();

	////�ָ�֮ǰ״̬
	//lixiaoyao->RocoveryState(*stateAdmin->GetMomento());
	//lixiaoyao->StateDisplay();

	//delete lixiaoyao;
	//delete stateAdmin;

	/*���ģʽ*/
	//Company* root=new ConcreteCompany("�����ܹ�˾");  
	//root->Add(new HRDepartment("�ܹ�˾������Դ��"));  
	//root->Add(new FinanceDepartment("�ܹ�˾����"));  

	//Company* comp=new ConcreteCompany("�Ϻ������ֹ�˾");  
	//comp->Add(new HRDepartment("�����ֹ�˾������Դ��"));  
	//comp->Add(new FinanceDepartment("�����ֹ�˾����"));  

	//root->Add(comp);  

	//Company* comp1=new ConcreteCompany("�Ͼ����´�");  
	//comp1->Add(new HRDepartment("�Ͼ����´�������Դ��"));  
	//comp1->Add(new FinanceDepartment("�Ͼ����´�����"));  

	//comp->Add(comp1);  

	//Company* comp2=new ConcreteCompany("���ݰ��´�");  
	//comp2->Add(new HRDepartment("���ݰ��´�������Դ��"));  
	//comp2->Add(new FinanceDepartment("���ݰ��´�����"));  

	//comp->Add(comp2);  

	//std::cout<<"�ṹͼ��"<<std::endl<<std::endl;  
	//root->Display(1);  

	//std::cout<<std::endl<<"ְ��"<<std::endl<<std::endl;  
	//root->LineOfDuty();  

	//delete root;  

	/*������ģʽ*/
	////�����������ۼ�����  
	//ConcreteAggregate* a=new ConcreteAggregate();  

	////�������ĳ˿�  
	//a->GetVector()->push_back("����");  
	//a->GetVector()->push_back("С��");  
	//a->GetVector()->push_back("����");  
	//a->GetVector()->push_back("����");  
	//a->GetVector()->push_back("�����ڲ���Ա");  
	//a->GetVector()->push_back("С͵");  

	////��ƱԱ�������ȿ������ϳ�������Щ�ˣ��������˵���������  
	////�������ֻ�ȡ�������ķ���������  
	////Iterator* i=new ConcreteIterator(a);  

	////������ǰ����ĵ�����  
	//Iterator* it1=a->CreateIterator();  

	////��֪ÿһλ�˿���Ʊ  
	//std::cout<<"��ǰ����ĵ�������"<<std::endl<<std::endl;  
	//while(!it1->IsDone())  
	//{  
	//	std::cout<<it1->CurrentItem()<<"  ����Ʊ��"<<std::endl;  
	//	it1->Next();  
	//}  
	//std::cout<<std::endl;  

	////�����Ӻ���ǰ�ĵ�����  
	//Iterator* it2=a->CreateIteratorDesc();  

	////��֪ÿһλ�˿���Ʊ  
	//std::cout<<"�Ӻ���ǰ�ĵ�������"<<std::endl<<std::endl;  
	//while(!it2->IsDone())  
	//{  
	//	std::cout<<it2->CurrentItem()<<"  ����Ʊ��"<<std::endl;  
	//	it2->Next();  
	//}  
	//std::cout<<std::endl<<std::endl;  

	//delete a,it1,it2;  
	
	/*�Ž�ģʽ*/
	////�ֻ�Ʒ��N
	//std::cout<<"�ֻ�Ʒ��N��"<<std::endl;  
	//HandsetBrand* ab=new HandsetBrandN();  
	//ab->SetHandsetSoft(new HandsetGame());  
	//ab->Run(); 

	//ab->SetHandsetSoft(new HandsetAddressList());  
	//ab->Run();  

	//delete ab;  

	////�ֻ�Ʒ��M  
	//std::cout<<std::endl<<"�ֻ�Ʒ��M��"<<std::endl;  
	//ab=new HandsetBrandM();  

	//ab->SetHandsetSoft(new HandsetGame());  
	//ab->Run();  

	//ab->SetHandsetSoft(new HandsetAddressList());  
	//ab->Run();  

	//delete ab;  
	//ab=NULL;  
	
	
	/*����ģʽ*/      //����ǰ��׼��  
	//Barbecuer* boy=new Barbecuer();  

	//Command* bakeMuttonCommand1=new BakeMuttonCommand(boy);  
	//Command* bakeMuttonCommand2=new BakeMuttonCommand(boy);  
	//Command* bakeChickenWingCommand1=new BakeChickenWingCommand(boy);  

	//Waiter* girl=new Waiter();  

	////����Ӫҵ���˿͵��  
	//girl->SetOrder(bakeMuttonCommand1);  
	//girl->SetOrder(bakeMuttonCommand2);  
	//girl->SetOrder(bakeChickenWingCommand1);  

	////�����ϣ�֪ͨ����  
	//girl->Notify();  

	//delete boy,bakeMuttonCommand1,bakeMuttonCommand2,bakeChickenWingCommand1;  
	
	/*������ģʽ*/
    //Manager *jinli=new CommonManager("����");
	//Manager *zongjian=new Majordomo("�ܼ�");
	//Manager *zongjinli=new GeneralManager("�ܾ���");

	////�����ϼ�  ��ʵ��������и���
	//jinli->SetSuperior(zongjian);
	//zongjian->SetSuperior(zongjinli);

	////������4������  
	////����1�����1��  
	//Request request1;  
	//request1.SetType("���");  
	//request1.SetContent("С�����");  
	//request1.SetNumber(1);  
	////�ͻ��˵����붼���ɡ��������𣬵�ʵ��˭�������ɾ���������������ͻ��˲�֪��  
	//jinli->RequestApplication(&request1);  

	////����2�����4��  
	//Request request2;  
	//request2.SetType("���");  
	//request2.SetContent("С�����");  
	//request2.SetNumber(4);  
	////�ͻ��˵����붼���ɡ��������𣬵�ʵ��˭�������ɾ���������������ͻ��˲�֪��  
	//jinli->RequestApplication(&request2);  

	////����3����н500Ԫ  
	//Request request3;  
	//request3.SetType("��н");  
	//request3.SetContent("С�������н");  
	//request3.SetNumber(500);  
	////�ͻ��˵����붼���ɡ��������𣬵�ʵ��˭�������ɾ���������������ͻ��˲�֪��  
	//jinli->RequestApplication(&request3);  

	////����4����н1000Ԫ  
	//Request request4;  
	//request4.SetType("��н");  
	//request4.SetContent("С�������н");  
	//request4.SetNumber(1000);  
	////�ͻ��˵����붼���ɡ��������𣬵�ʵ��˭�������ɾ���������������ͻ��˲�֪��  
	//jinli->RequestApplication(&request4);  

	//delete jinli,zongjian,zongjinli;  
	
	/*�н���ģʽ*/
	UnitedNationsSecurityCouncil *un=new UnitedNationsSecurityCouncil();
	Country *usa=new USA(un);
	Country *iraq=new Iraq(un);

	un->SetColleague1(usa);
	un->SetColleague2(iraq);

	usa->Declare("��׼�з�������");
	iraq->Declare("����û���з�������");

	system("pause");
	return 0;
}
