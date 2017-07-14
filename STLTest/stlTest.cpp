#include "stlTest.h"

using namespace std;

void vector_test1(){
	//create a empty vector for strings
	vector<string> sentence;
	//开辟一个容纳5个元素的空间，size可没变
	sentence.reserve(5);
	//添加 some elements
	sentence.push_back("Hello,");
	sentence.push_back("how");
	sentence.push_back("are");
	sentence.push_back("you");
	sentence.push_back("?");

	//打印出sentence中的内容
	copy(sentence.begin(),sentence.end(),ostream_iterator<string>(cout," "));
	cout<<endl;

	//print ''technical data''  
	cout << " max_size(): " << sentence.max_size() << endl;  //最大可能长度 是很大一个数
	cout << " size():     " << sentence.size()     << endl;  //已添加的元素个数
	cout << " capacity(): " << sentence.capacity() << endl;  //已分配内存的当前长度

	//交换第2和第4个元素
	swap(sentence[1],sentence[3]);

	//使用迭代器 
	vector<string>::iterator it1=sentence.begin();
	vector<string>::iterator it2=sentence.end();

	cout<<*it1<<endl;
	cout<<*(it2-1)<<endl;

	//在“？”前插入元素 “always”
	sentence.insert(find(sentence.begin(),sentence.end(),"?"),"always");

	//下面两条语句将 引发迭代器失效  vector iterator not dereferencable 
	/*
	cout<<*it1<<endl;
	cout<<*(it2-1)<<endl;
	*/

	//assign "!" to the last element
	sentence.back()="!";
	copy(sentence.begin(),sentence.end(),ostream_iterator<string>(cout," "));
	cout<<endl;


	cout << " max_size(): " << sentence.max_size() << endl;  //最大可能长度 是很大一个数
	cout << " size():     " << sentence.size()     << endl;  //已添加的元素个数
	cout << " capacity(): " << sentence.capacity() << endl;  //已分配内存的当前长度

}

void list_test1(){
	list<int> coll;
	//6 5 4 3 2 1 1 2 3 4 5 6
	for(int i=1;i<=6;i++){
		coll.push_front(i);
		coll.push_back(i);
	}
	//打印
	cout<<"pre: ";
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	//全局remove（）函数
	//remove(coll.begin(),coll.end(),3);

	//list的remove函数
	coll.remove(3);

	//打印
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
	//find（）返回元素3 的迭代器位置
	//把list1中的所有元素 插入到list2中元素3之前  splice	拼接
	list2.splice(find(list2.begin(),list2.end(),3),list1);
	printLists(list1,list2);
	
	//相当于倒置  ？？？
	list2.splice(list2.end(), list2, list2.begin());  
	printLists(list1, list2); 

	//排序 并去掉重复
	list2.sort();
	list1=list2;
	list2.unique();
	printLists(list1,list2);

	//合并
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

	//再次插入4
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
	/*advance 函数的测试*/
	list<int>::iterator pos=coll.begin();
	cout<<*pos<<endl;
	advance(pos,3);
	cout<<*pos<<endl;
	advance(pos,-1);
	cout<<*pos<<endl;

	/*distance函数的测试*/
	pos=find(coll.begin(),coll.end(),5);
	if(pos!=coll.end()){
		cout<<"distance between beginning and 5: "
			<<distance(coll.begin(),pos)<<endl;
	}else{
		cout<<"5 not found"<<endl;
	}

	/*iter_swap函数的测试*/
	//swap first and second value  
	iter_swap (coll.begin(), ++coll.begin());  //++coll.begin()返回的是coll.begin()+1后的值
	//iter_swap (coll.begin(), coll.begin()++);  //coll.begin()++返回的是coll.begin()原来的值
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	//swap first and last value  
	iter_swap (coll.begin(), --coll.end()); //--coll.end()返回的是coll.end()-1后的值
	//iter_swap (coll.begin(), coll.end()--);  //出错  coll.end()--返回的是coll.end()原来的值
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	
}