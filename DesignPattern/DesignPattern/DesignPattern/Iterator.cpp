#include "Iterator.h"

//��ǰ����ĵ������ĳ�Ա����ʵ�� 
ConcreteIterator::ConcreteIterator(Aggregate* aggregate){
	this->aggregate=(ConcreteAggregate*)aggregate;
	current=0;
}

object ConcreteIterator::First(){
	return aggregate->GetVector()->at(0);
}

object ConcreteIterator::Next(){
	current++;
	if(current<aggregate->GetVector()->size()){
		return aggregate->GetVector()->at(current);
	}
}

bool ConcreteIterator::IsDone(){
	return current>=aggregate->GetVector()->size()?true:false;
}

object ConcreteIterator::CurrentItem()  
{  
	return aggregate->GetVector()->at(current);  
}  



//�Ӻ���ǰ�ĵ������ĳ�Ա����ʵ�� 
ConcreteIteratorDesc::ConcreteIteratorDesc(Aggregate* aggregate){  
	this->aggregate=(ConcreteAggregate*)aggregate;  
	current=(((ConcreteAggregate*)aggregate)->GetVector()->size())-1;  
}

object ConcreteIteratorDesc::First(){  
	return *(aggregate->GetVector()->end());  
}  

object ConcreteIteratorDesc::Next(){  
	current--;  
	if(current>=0)  
		return aggregate->GetVector()->at(current);  
}  

bool ConcreteIteratorDesc::IsDone(){  
	return current<0?true:false;  
}  

object ConcreteIteratorDesc::CurrentItem(){  
	return aggregate->GetVector()->at(current);  

} 