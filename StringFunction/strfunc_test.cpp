#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<malloc.h>
#include<assert.h>


#define MALLOC_TEST	//内存分配函数测试
#define MEMSET_TEST	//初始化内存函数测试
//#define MEMCPY_TEST	//内存复制函数测试
//#define STRLEN_TEST	//字符串长度函数测试
//#define STRCAT_TEST	//字符串连接诶测试
//#define STRCPY_TEST	//字符串复制测试
//#define STRCMP_TEST	//字符串比较测试


/****************************************************************************************
1.strlen函数求字符数组或者字符串的长度，不包含结束符

2.void *memset(void *s,char ch,unsigned n)将s所指向的某一块内存中的每个字节的内容全部设置
为ch指定的ASCii值，块的大小由第三个参数确定，这个函数通常为新申请的内存做初始化工作.

3.memset() 函数常用于内存空间初始化。如：
char str[100];
memset(str,0,100); 

4.memset()的深刻内涵:用来对一段内存空间全部设置为某个字符，一般用在对定义的字符串初始化为
‘memset(a,'\0',sizeof(a))’

5.memcpy 函数原型void * memcpy(char *strDest, const char *strSrc, int Count)
memcpy用来做内存拷贝，可以拷贝任何数据类型的对象，可以指定拷贝数据的长度
例：char a[100],b[50]; memcpy(b, a, sizeof(b));注意如用sizeof(a)，会造成b的内存地址溢出。 

6.strcpy就只能拷贝字符串了，它遇到'\0'就结束拷贝；例：char a[100],b[50];strcpy(a,b);
如用strcpy(b,a)，要注意a中的字符串长度（第一个‘\0’之前）是否超过50位，如超过，则会造成
b的内存地址溢出。

7.memset可以方便的清空一个结构类型的变量或数组。
　　如：
　　struct sample_struct
　　{
　　	  char csName[16];
　　	  int iSeq;
　　	  int iType;
　　};

　　对于变量
　　struct sample_strcut stTest;
　　一般情况下，清空stTest的方法：
　　stTest.csName[0]='\0';
　　stTest.iSeq=0;
　　stTest.iType=0;

　　用memset就非常方便：
　　memset(&stTest,0,sizeof(struct sample_struct));

　　如果是数组：
　　struct sample_struct TEST[10];
　　则
　　memset(TEST,0,sizeof(struct sample_struct)*10); 

8.  strcpy
	原型：extern char *strcpy(char *dest,char *src);
　　用法：＃include
　　功能：把src所指由NULL结束的字符串复制到dest所指的数组中。
　　说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。
　　返回指向dest的指针。

　　memcpy
　　原型：extern void *memcpy(void *dest, void *src, unsigned int count);
　　用法：＃include
　　功能：由src所指内存区域复制count个字节到dest所指内存区域。
　　说明：src和dest所指内存区域不能重叠，函数返回指向dest的指针。

　　memset
　　原型：extern void *memset(void *buffer, int c, int count);
　　用法：＃include
　　功能：把buffer所指内存区域的前count个字节设置成字符c。
　　说明：返回指向buffer的指针。 
****************************************************************************************/

#ifdef STRCAT_TEST
char *strcata(char *strDest,const char* strSrc)
{
	char *address=strDest;
	assert((strDest!=NULL&&strSrc!=NULL));
	while(*strDest){
		strDest++;
	}
	while(*strDest++=*strSrc++){
		NULL;		
	}
	return address;
}

#endif
#ifdef STRCPY_TEST
char * strcpya(char *strDest,const char *strSrc){
	char *address=strDest;
	assert((strDest!=NULL)&&(strSrc!=NULL));
	while(*strSrc){
		*strDest++=*strSrc++;
	}
	*strDest='\0';
	return address;
	
}
#endif
#ifdef STRCMP_TEST
int strcmpa(const char *str1,const char* str2){
	assert((str1!='\0')&&(str2!='\0'));
	while(*str1&&*str2&&(*str1==*str2)){
		str1++;
		str2++;
	}
	return *str1-*str2;
}
#endif

void main(){

#ifdef STRLEN_TEST
	char buffer[]="Hello World";//a为数组名 是地址 常指针   自动加上结束符‘\0’所以a中共有12个字符
	char *s="Hello World";//s为指针变量 是地址

	printf("%s has %d chars\n",buffer,strlen(buffer));//11
	printf("%s has %d chars\n",s,strlen(s));//11
	printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("%s has %d bytes\n",buffer,sizeof(buffer));//12  buffer为一个数组 这里求的是数组的字节数 
	printf("%s has %d bytes\n",s,sizeof(s));//4 s为指针型变量展4个字节
	printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");
#endif

#ifdef MEMSET_TEST
	char buffer[]="Hello World";//a为数组名 是地址 常指针   自动加上结束符‘\0’所以a中共有12个字符
	char *s="Hello World";//s为指针变量 是地址

	printf("Buffer before memset: %s \n",buffer);
	memset(buffer,'*',strlen(buffer));
	printf("Buffer after memset: %s \n",buffer);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");

	memset(buffer,'A',5);
	printf("Buffer:%s \n",buffer);

	//这里有很大的问题程序根本就运行不下去了，这里的s指向的是一段只读的内存，
	//memset试图修改它，所以运行时要出错，修改办法char *s修改为char s[]
	//memset(s,'A',5);
	//printf("Buffer:%s \n",s);
#endif

#ifdef MALLOC_TEST
	char *p;
	p=(char *)malloc(100);
	if(p)
		printf("Memory Allocated at: %x\n",p);
	else
		printf("Not Enough Memory!\n");
	free(p);
#endif

#ifdef MATRIX_TEST
	int row=1;
	int start=1;
	int data=start;
	int stepr=row+1;
	int stepd=1;
	int N=10;
	int i=0;
	while(N){
		for( i=1;i<=N;i++){
			printf("%4d",data);
			data+=stepr;
			stepr++;
			if(i==N)
				printf("\n");
		}
		row++;
		stepr=row+1;
		stepd=row-1;;
		start+=stepd;
		data=start;
		N--;
	}
#endif

#ifdef STRCAT_TEST

	char str1[100]={"I Love "};
	char str2[50]={"China"};
	printf("%s\n",strcata(str1,str2));
#endif

#ifdef STRCPY_TEST
	char str1[20]="I Love China";//字符串都会自动加上结束符   I Love China 占13个字节，当数组大小为12时，该赋值语句不合法 
	//当源字符串长度(不包含结束符)大于等于（因为最后还要加上一个‘\0’）目的地址所指向的内存（字节）长度时，会报运行时错误
	//当源字符串长度大于目的字符串长度时，会报运行时错误
	char str2[]="You Love China";
	printf("%s\n",strcpya(str1,str2));

	//char *str3="I Love China";//报错  因为str3指向的是一段只读的内存 换成s3[]
	//char *str4="U Love China";
	//printf("%s\n",strcpya(str3,str4));
#endif

#ifdef STRLEN_TEST
	char *str1="China";
	char *str2={"China"};
	char str3[]="China";
	char str4[]={"China"};
	char str5[20]="China";
	char str6[20]={"China"};

	printf("strlen(str1):%d\n",strlen(str1));//5
	printf("sizeof(str1):%d\n",sizeof(str1));//4
	printf("strlen(str2):%d\n",strlen(str2));//5
	printf("sizeof(str2):%d\n",sizeof(str2));//4
	printf("strlen(str3):%d\n",strlen(str3));//5
	printf("sizeof(str3):%d\n",sizeof(str3));//6
	printf("strlen(str4):%d\n",strlen(str4));//5
	printf("sizeof(str4):%d\n",sizeof(str4));//6
	printf("strlen(str5):%d\n",strlen(str5));//5
	printf("sizeof(str5):%d\n",sizeof(str5));//20
	printf("strlen(str6):%d\n",strlen(str6));//5
	printf("sizeof(str6):%d\n",sizeof(str6));//20
#endif


}