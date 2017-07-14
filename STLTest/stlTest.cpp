#include "stlTest.h"

using namespace std;

void vector_test1(){
	//create a empty vector for strings
	vector<string> sentence;
	//����һ������5��Ԫ�صĿռ䣬size��û��
	sentence.reserve(5);
	//��� some elements
	sentence.push_back("Hello,");
	sentence.push_back("how");
	sentence.push_back("are");
	sentence.push_back("you");
	sentence.push_back("?");

	//��ӡ��sentence�е�����
	copy(sentence.begin(),sentence.end(),ostream_iterator<string>(cout," "));
	cout<<endl;

	//print ''technical data''  
	cout << " max_size(): " << sentence.max_size() << endl;  //�����ܳ��� �Ǻܴ�һ����
	cout << " size():     " << sentence.size()     << endl;  //����ӵ�Ԫ�ظ���
	cout << " capacity(): " << sentence.capacity() << endl;  //�ѷ����ڴ�ĵ�ǰ����

	//������2�͵�4��Ԫ��
	swap(sentence[1],sentence[3]);

	//ʹ�õ����� 
	vector<string>::iterator it1=sentence.begin();
	vector<string>::iterator it2=sentence.end();

	cout<<*it1<<endl;
	cout<<*(it2-1)<<endl;

	//�ڡ�����ǰ����Ԫ�� ��always��
	sentence.insert(find(sentence.begin(),sentence.end(),"?"),"always");

	//����������佫 ����������ʧЧ  vector iterator not dereferencable 
	/*
	cout<<*it1<<endl;
	cout<<*(it2-1)<<endl;
	*/

	//assign "!" to the last element
	sentence.back()="!";
	copy(sentence.begin(),sentence.end(),ostream_iterator<string>(cout," "));
	cout<<endl;


	cout << " max_size(): " << sentence.max_size() << endl;  //�����ܳ��� �Ǻܴ�һ����
	cout << " size():     " << sentence.size()     << endl;  //����ӵ�Ԫ�ظ���
	cout << " capacity(): " << sentence.capacity() << endl;  //�ѷ����ڴ�ĵ�ǰ����

}

void list_test1(){
	list<int> coll;
	//6 5 4 3 2 1 1 2 3 4 5 6
	for(int i=1;i<=6;i++){
		coll.push_front(i);
		coll.push_back(i);
	}
	//��ӡ
	cout<<"pre: ";
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	//ȫ��remove��������
	//remove(coll.begin(),coll.end(),3);

	//list��remove����
	coll.remove(3);

	//��ӡ
	cout<<"post: ";
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
}

void printLists(const list<int>& list1,const list<int>& list2 ){
	cout<<"list1: ";
	copy(list1.begin(),list1.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	cout<<"list2: ";
	copy(list2.begin(),list2.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
}

void list_test2(){
	list<int> list1,list2;
	for(int i=0;i<6;i++){
		list1.push_back(i);//0 1 2 3 4 5
		list2.push_front(i);//5 4 3 2 1 0
	}
	printLists(list1,list2);
	//find��������Ԫ��3 �ĵ�����λ��
	//��list1�е�����Ԫ�� ���뵽list2��Ԫ��3֮ǰ  splice	ƴ��
	list2.splice(find(list2.begin(),list2.end(),3),list1);
	printLists(list1,list2);
	
	//�൱�ڵ���  ������
	list2.splice(list2.end(), list2, list2.begin());  
	printLists(list1, list2); 

	//���� ��ȥ���ظ�
	list2.sort();
	list1=list2;
	list2.unique();
	printLists(list1,list2);

	//�ϲ�
	list1.merge(list2);
	printLists(list1,list2);
}

void set_test1(){

	typedef set<int,greater<int>> IntSet;
	IntSet coll1;//empty set container
	//insert elements in random order
	coll1.insert(4);
	coll1.insert(3);
	coll1.insert(5);
	coll1.insert(1);
	coll1.insert(6);
	coll1.insert(2);
	coll1.insert(5);

	//iterator over all elements and print them
	IntSet::iterator pos;
	for(pos=coll1.begin();pos!=coll1.end();++pos){
		cout<<*pos<<' ';
	}
	cout<<endl;

	//�ٴβ���4
	pair<IntSet::iterator,bool> status=coll1.insert(4);
	if(status.second){
		cout<<"4 inserted as element  "
			<<distance(coll1.begin(),status.first)+1
			<<endl;

	}
	else{
		cout<<"4 already exists"<<endl;
	}

	//assign elements to another set with ascending order
	set<int> coll2(coll1.begin(),coll1.end());

	//print all elements of the copy
	copy(coll2.begin(),coll2.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	//remove all elements up to element with value 3
	coll2.erase(coll2.begin(),coll2.find(3));

	//remove all elements with value 5
	int num;
	num=coll2.erase(5);
	cout<<num<<"elements removed"<<endl;

	//print all elements
	copy(coll2.begin(),coll2.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

}

void iterator_test1(){

	list<int> coll;
	for(int i=1;i<=9;i++){
		coll.push_back(i);
	}
	/*advance �����Ĳ���*/
	list<int>::iterator pos=coll.begin();
	cout<<*pos<<endl;
	advance(pos,3);
	cout<<*pos<<endl;
	advance(pos,-1);
	cout<<*pos<<endl;

	/*distance�����Ĳ���*/
	pos=find(coll.begin(),coll.end(),5);
	if(pos!=coll.end()){
		cout<<"distance between beginning and 5: "
			<<distance(coll.begin(),pos)<<endl;
	}else{
		cout<<"5 not found"<<endl;
	}

	/*iter_swap�����Ĳ���*/
	//swap first and second value  
	iter_swap (coll.begin(), ++coll.begin());  //++coll.begin()���ص���coll.begin()+1���ֵ
	//iter_swap (coll.begin(), coll.begin()++);  //coll.begin()++���ص���coll.begin()ԭ����ֵ
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	//swap first and last value  
	iter_swap (coll.begin(), --coll.end()); //--coll.end()���ص���coll.end()-1���ֵ
	//iter_swap (coll.begin(), coll.end()--);  //����  coll.end()--���ص���coll.end()ԭ����ֵ
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	
}