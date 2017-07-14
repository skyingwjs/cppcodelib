/************************************************************************
基本代码实现
//Component类
class Component{
public:
	virtual void Operation()=0;  
};

//ConcreteComponent类
class ConcreteComponent: public Component{
public:
	void Operation(){
		cout<<"具体对象的操作"<<endl;
	}
};

//Decorator类
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

//ConcreteDecoratorA类
class ConcreteDecoratorA:public Decorator{
private:
	//本类独有的方法，以区别于ConcreteDecoratorB
	string addState;
public:
	//首先运行Component的Operation(),再执行本类的功能，如addState，相当于对原Compon
	void Operation(){
		super.Operation();
		addState="new state";
		cout<<"具体装饰对象A的操作"<<endl;
	}
};

//ConcreteDecoratorB类
class ConcreteDecoratorB:public Decorator{
private:
	//本类独有的方法，以区别于ConcreteDecoratorA
	void addBehavior(){

	}
public:
	//首先运行Component的Operation(),再执行本类的功能，如addBehavior，相当于对原Component进行了装饰
	void Operation(){
		super.Operation();
		addBehavior();
		cout<<"具体装饰对象B的操作"<<endl;
	}
};
************************************************************************/
