#ifndef _MEMENTO_PATTERN_
#define _MEMENTO_PATTERN_
#include <iostream>
#include <string>

//Memento类，备忘录，此处为角色状态存储箱RoleStateMemento class  
class RoleStateMemento{
private:  
	//生命力  
	int vit;  
	//攻击力  
	int atk;  
	//防御力  
	int def;  
public:
	RoleStateMemento(int vit,int atk,int def){
		this->vit=vit;
		this->atk=atk;
		this->def=def;
	}

	int GetVitality(){
		return vit;
	}
	void SetVitality(int vit){  
		this->vit=vit;  
	}  
	int GetAttack(){  
		return atk;  
	}  
	void SetAttack(int atk){  
		this->atk=atk;  
	}  
	int GetDefense()  {  
		return def;  
	}  
	void SetDefense(int def){  
		this->def=def;  
	}  
};


//Originator，发起人，此处为游戏角色，GameRole class  
class GameRole  
{  
private:  
	//生命力  
	int vit;  
	//攻击力  
	int atk;  
	//防御力  
	int def;  

public:  
	int GetVitality()  
	{  
		return vit;  
	}  
	void SetVitality(int vit)  
	{  
		this->vit=vit;  
	}  
	int GetAttack()  
	{  
		return atk;  
	}  
	void SetAttack(int atk)  
	{  
		this->atk=atk;  
	}  
	int GetDefense()  
	{  
		return def;  
	}  
	void SetDefense(int def)  
	{  
		this->def=def;  
	}  

	void GetInitState()  
	{  
		this->vit=100;  
		this->atk=100;  
		this->def=100;  
	}  
	void Fight()  
	{  
		this->vit=0;  
		this->atk=0;  
		this->def=0;  
	}  
	void StateDisplay()  
	{  
		std::cout<<"当前角色状态："<<std::endl;  
		std::cout<<"体力："<<this->vit<<std::endl;  
		std::cout<<"生命力："<<this->atk<<std::endl;  
		std::cout<<"防御力："<<this->def<<std::endl<<std::endl;  
	}  

	//“保存角色状态”方法，将游戏角色的三个状态值通过实例化“角色状态存储箱”返回  
	RoleStateMemento* SaveState()  
	{  
		return new RoleStateMemento(vit,atk,def);  
	}  

	//“恢复角色状态”方法，可将外部的“角色状态存储箱”中的状态值恢复给游戏角色  
	void RocoveryState(RoleStateMemento memento)  
	{  
		this->vit=memento.GetVitality();  
		this->atk=memento.GetAttack();  
		this->def=memento.GetDefense();  
	}  
};  

//Caretaker，管理者，此处为游戏角色管理类，RoleStateCaretaker class  
class RoleStateCaretaker{
private:
	RoleStateMemento *memento;
public:
	RoleStateCaretaker(){
		memento=NULL;
	}

	~RoleStateCaretaker(){
		if(memento!=NULL){
			delete memento;
			memento=NULL;
		}
	}

	RoleStateMemento *GetMomento(){
		return memento;
	}

	void SetMemento(RoleStateMemento *memento){
		this->memento=memento;
	}
};






#endif