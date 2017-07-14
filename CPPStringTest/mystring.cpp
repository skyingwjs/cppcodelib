#include "mystring.h"
void MyString::stringTest1(){

	//1.string类的重载运算符 operator>>用于输入，同样重载运算符operator<<用于输出
	cout<<"========= 1.string类的重载运算符 ==========="<<endl;
	string str1;
	cout<<"请输入字符串： ";
	cin>>str1;//当cin>>进行字符串输入的时候，遇到空格的地方就停止字符串的读取输入
	cout<<str1<<endl;

	cout<<"请输入字符串： ";
	cin.get();//读取cin>>输入的结束符，不用对getline的输入产生影响
	getline(cin,str1);
	cout<<str1<<endl;

	//2.string类的构造函数
	cout<<endl;
	cout<<"========= 2.string类的构造函数 ==========="<<endl;
	string str2="aaaaa";//最简单的字符串初始化
	cout<<str2<<endl;

	char *s="bbbbb";
	string str3(s);//用c类型 字符串s初始化
	cout<<str3<<endl;

	char ch='c';
	string str4(5,ch);//用n个字符初始化
	cout<<str4<<endl;

	//3.string类的字符操作
	cout<<endl;
	cout<<"========= 3.string类的字符操作 ==========="<<endl;
	string str5="abcde";
	ch=str5[3];//operator[] 返回当前字符串第n个字符的位置
	cout<<ch<<endl;

	string str6="abcde";
	ch=str6.at(4);//at()返回当前字符串中第n个字符的位置,并且提供范围检查，当越界时会抛出异常！    
	cout<<ch<<endl;

	//4.string类的特性描述
	cout<<endl;
	cout<<"========= 4.string类的特性描述 ==========="<<endl;
	string str7="abcdefgh";
	int size;

	size=str7.capacity();//返回当前容量   
	cout<<"capacity:"<<size<<endl;

	size=str7.max_size();//返回string对象中可存放的最大字符串的长度   
	cout<<"max_size:"<<size<<endl;

	size=str7.size();//返回当前字符串的大小   
	cout<<"size"<<size<<endl;

	size=str7.length();//返回当前字符串的长度   
	cout<<"length:"<<size<<endl;

	bool flag;
	flag=str7.empty();//判断字符串是否为空
	cout<<"is empty:"<<flag<<endl;

	int len =10;
	str7.resize(len,ch);//将字符串当前大小置为len 并用ch填充不足的部分
	cout<<str7<<endl;

	//5.string 的赋值
	cout<<endl;
	cout<<"========= 5.string 的赋值 ==========="<<endl;
	string str8;
	str8=str7;//把字符串str7赋给当前字符串  
	cout<<"str8:"<<str8<<endl;

	str8.assign(str7);
	cout<<"str8:"<<str8<<endl;

	str8.assign(s);//用c类型字符串s赋值
	cout<<"str8:"<<str8<<endl;

	str8.assign(s,2);//用c类型字符串s开始的n和字符赋值
	cout<<"str8:"<<str8<<endl;

	str8.assign(len,ch);//用len个字符ch赋值给当前字符串
	cout<<"str8:"<<str8<<endl;

	str8.assign(str7,0,3);//把字符串str7中从第0个开始的3个字符赋值给当前字符串
	cout<<"str8:"<<str8<<endl;

	string str9="0123456789";
	str8.assign(str9.begin(),str9.end());//将迭代器之间的字符赋值给字符串
	cout<<"str8:"<<str8<<endl;

	//6.字符串的连接
	cout<<endl;
	cout<<"========= 6.字符串的连接 ==========="<<endl;
	string str10;
	str10+=str9;//把字符串str9连接到当前字符串的结尾
	cout<<"str10:"<<str10<<endl;

	str10.append(s);//将c类型的字符串连接到当前字符串结尾
	cout<<"str10:"<<str10<<endl;

	str10.append(s,2);//把c类型字符串s的前2个字符连接到当前字符串的结尾  
	cout<<"str10:"<<str10<<endl;

	str10.append(str9.begin(),str9.end());//把迭代器之间的一段字符连接到当前字符串的结尾 
	cout<<"str10:"<<str10<<endl;

	str10.push_back('k');//将一个字符连接到当前字符串结尾
	cout<<"str10:"<<str10<<endl;

	//7.string 的比较
	cout<<endl;
	cout<<"========= 7.string 的比较 ==========="<<endl;
	flag=(str9==str10);//判断两个字符串是否相等
	cout<<"str9==str10"<<flag<<endl;
	flag=(str9!=str10);
	cout<<"str9!=str10"<<flag<<endl;
	flag=(str9>str10);
	cout<<"str9>str10"<<flag<<endl;
	flag=(str9<str10);
	cout<<"str9<str10"<<flag<<endl;
	flag=(str9>=str10);
	cout<<"str9>=str10"<<flag<<endl;
	flag=(str9<=str10);
	cout<<"str9<=str10"<<flag<<endl;

	//以下的3个函数同样适用于c类型的字符串，在compare函数中>时返回1，<时返回-1，=时返回0   
	flag = str10.compare(str9);//比较两个字符串的大小，通过ASCII的相减得出！   
	cout << flag << endl;   
	flag = str10.compare(6, 12, str9);//比较str10字符串从6开始的12个字符组成的字符串与str9的大小   
	cout << flag << endl;  
	flag = str10.compare(6, 12, str9, 3, 5);//比较str10字符串从6开始的12个字符组成的字符串与str9字符串从3开始的5个字符组成的字符串的大小   
	cout << flag << endl;   

	//8.string 的子串
	cout<<endl;
	string str11;
	cout<<"========= 8.string 的子串 ==========="<<endl;
	str11=str10.substr(10,15);//返回从下标10开始的15个字符组成的字符串  
	cout<<str11<<endl;

	//9.string的交换swap
	cout<<endl;
	cout<<"========= 9.string的交换swap ==========="<<endl;
	str11.swap(str10);//交换str11与str10的值   
	cout << str11 << endl;   

	//10.string的查找，查找成功时返回所在位置，失败时返回string::npos的值，即是-1   
	cout<<endl;
	cout<<"========= 10.string的查找 ==========="<<endl;
	string str12 = "abcdefghijklmnopqrstuvwxyz";  
	int pos;  
	pos=str12.find('i',0);//从位置0开始查找字符i在当前字符串的位置
	cout<<pos<<endl;
	pos = str12.find("ghijk", 0);//从位置0开始查找字符串“ghijk”在当前字符串的位置   
	cout << pos << endl;   
	pos = str12.find("opqrstuvw", 0, 4);//从位置0开始查找字符串“opqrstuvw”前4个字符组成的字符串在当前字符串中的位置   
	cout << pos << endl;   
	pos = str12.rfind('s', string::npos);//从字符串str12反向开始查找字符s在字符串中的位置   
	cout << pos << endl;   
	pos = str12.rfind("klmn", string::npos);//从字符串str12反向开始查找字符串“klmn”在字符串中的位置   
	cout << pos << endl;  
	pos = str12.rfind("opqrstuvw", string::npos, 3);//从string::pos开始从后向前查找字符串s中前n个字符组成的字符串在当前串中的位置   
	cout << pos << endl;  

	string str13 = "aaaabbbbccccdddeeefffggghhhiiijjjkkllmmmandjfaklsdfpopdtwptioczx";  
	pos = str13.find_first_of('d', 0);//从位置0开始查找字符d在当前字符串第一次出现的位置   
	cout << pos << endl;   
	pos = str13.find_first_of("eefff", 0);//从位置0开始查找字符串“eeefff“在当前字符串中第一次出现的位置   
	cout << pos << endl;   
	pos = str13.find_first_of("efff", 0, 3);//从位置0开始查找当前串中第一个在字符串”efff“的前3个字符组成的数组里的字符的位置   
	cout << pos << endl;  
	pos = str13.find_first_not_of('b', 0);//从当前串中查找第一个不在串s中的字符出现的位置   
	cout << pos << endl;   
	pos = str13.find_first_not_of("abcdefghij", 0);//从当前串中查找第一个不在串s中的字符出现的位置   
	cout << pos << endl;   
	pos = str13.find_first_not_of("abcdefghij", 0, 3);//从当前串中查找第一个不在由字符串”abcdefghij”的前3个字符所组成的字符串中的字符出现的位置   
	cout << pos << endl;   
	
	
	//下面的last的格式和first的一致，只是它从后面检索！   
	pos = str13.find_last_of('b', string::npos);  
	cout << pos << endl;  
	pos = str13.find_last_of("abcdef", string::npos);  
	cout << pos << endl;  
	pos = str13.find_last_of("abcdef", string::npos, 2);  
	cout << pos << endl;   
	pos = str13.find_last_not_of('a', string::npos);  
	cout << pos << endl;   
	pos = str13.find_last_not_of("abcdef", string::npos);  
	cout << pos << endl;  
	pos = str13.find_last_not_of("abcdef", string::npos, 3);  
	cout << pos << endl; 


	//11.string的替换  
	cout<<endl;
	cout<<"========= 11.string的替换   ==========="<<endl;
	string str14 = "abcdefghijklmn";  
	str14.replace(0, 3, "qqqq");//删除从0开始的3个字符，然后在0处插入字符串“qqqq”   
	cout << str14 << endl;   
	str14.replace(0, 3, "vvvv", 2);//删除从0开始的3个字符，然后在0处插入字符串“vvvv”的前2个字符   
	cout << str14 << endl;   
	str14.replace(0, 3, "opqrstuvw", 2, 4);//删除从0开始的3个字符，然后在0处插入字符串“opqrstuvw”从位置2开始的4个字符   
	cout << str14 << endl;   
	str14.replace(0, 3, 8, 'c');//删除从0开始的3个字符，然后在0处插入8个字符 c   
	cout << str14 << endl;   
	//上面的位置可以换为迭代器的位置，操作是一样的，在这里就不再重复了！   

	//12.string的插入，下面的位置处亦可以用迭代器的指针表示，操作是一样的  
	cout<<endl;
	cout<<"========= 12.string的插入 ==========="<<endl;
	string str15 = "abcdefg";  
	str15.insert(0, "mnop");//在字符串的0位置开始处，插入字符串“mnop”   
	cout << str15 << endl;   
	str15.insert(0, 2, 'm');//在字符串的0位置开始处，插入2个字符m   
	cout << str15 << endl;   
	str15.insert(0, "uvwxy", 3);//在字符串的0位置开始处，插入字符串“uvwxy”中的前3个字符   
	cout << str15 << endl;  
	str15.insert(0, "uvwxy", 1, 2);//在字符串的0位置开始处，插入从字符串“uvwxy”的1位置开始的2个字符   
	cout << str15 << endl;   

	//13.string的删除  
	cout<<endl;
	cout<<"========= 13.string的删除  ==========="<<endl;
	string str16 = "gfedcba";  
	string::iterator it;  
	it = str16.begin();  
	it++;  
	str16.erase(it);//删除it指向的字符，返回删除后迭代器的位置   
	cout << str16 << endl;  
	str16.erase(it, it+3);//删除it和it+3之间的所有字符，返回删除后迭代器的位置   
	cout << str16 << endl;   
	str16.erase(2);//删除从字符串位置3以后的所有字符，返回位置3前面的字符   
	cout << str16 << endl;   

	//14.字符串的流处理  
	cout<<endl;
	cout<<"========= 14.字符串的流处理 ==========="<<endl;
	string str17("hello,this is a test");  
	istringstream is(str17);  
	string s1,s2,s3,s4;  
	is>>s1>>s2>>s3>>s4;//s1="hello,this",s2="is",s3="a",s4="test"  
	ostringstream os;  
	os<<s1<<s2<<s3<<s4;  
	cout<<os.str() << endl;  
}