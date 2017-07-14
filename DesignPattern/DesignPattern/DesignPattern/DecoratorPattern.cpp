/************************************************************************
��������ʵ��
//Component��
class Component{
public:
	virtual void Operation()=0;  
};

//ConcreteComponent��
class ConcreteComponent: public Component{
public:
	void Operation(){
		cout<<"�������Ĳ���"<<endl;
	}
};

//Decorator��
class Decorator:public Component{
protected:
	Component component;

public:
	void setComponent(Component component){
		this->component=component;
	}

	void Operation(){
		if(component!=NULL){
			component.Operation();
		}
	}

};

//ConcreteDecoratorA��
class ConcreteDecoratorA:public Decorator{
private:
	//������еķ�������������ConcreteDecoratorB
	string addState;
public:
	//��������Component��Operation(),��ִ�б���Ĺ��ܣ���addState���൱�ڶ�ԭCompon
	void Operation(){
		super.Operation();
		addState="new state";
		cout<<"����װ�ζ���A�Ĳ���"<<endl;
	}
};

//ConcreteDecoratorB��
class ConcreteDecoratorB:public Decorator{
private:
	//������еķ�������������ConcreteDecoratorA
	void addBehavior(){

	}
public:
	//��������Component��Operation(),��ִ�б���Ĺ��ܣ���addBehavior���൱�ڶ�ԭComponent������װ��
	void Operation(){
		super.Operation();
		addBehavior();
		cout<<"����װ�ζ���B�Ĳ���"<<endl;
	}
};
************************************************************************/
