#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<malloc.h>
#include<assert.h>


#define MALLOC_TEST	//�ڴ���亯������
#define MEMSET_TEST	//��ʼ���ڴ溯������
//#define MEMCPY_TEST	//�ڴ渴�ƺ�������
//#define STRLEN_TEST	//�ַ������Ⱥ�������
//#define STRCAT_TEST	//�ַ�������������
//#define STRCPY_TEST	//�ַ������Ʋ���
//#define STRCMP_TEST	//�ַ����Ƚϲ���


/****************************************************************************************
1.strlen�������ַ���������ַ����ĳ��ȣ�������������

2.void *memset(void *s,char ch,unsigned n)��s��ָ���ĳһ���ڴ��е�ÿ���ֽڵ�����ȫ������
Ϊchָ����ASCiiֵ����Ĵ�С�ɵ���������ȷ�����������ͨ��Ϊ��������ڴ�����ʼ������.

3.memset() �����������ڴ�ռ��ʼ�����磺
char str[100];
memset(str,0,100); 

4.memset()������ں�:������һ���ڴ�ռ�ȫ������Ϊĳ���ַ���һ�����ڶԶ�����ַ�����ʼ��Ϊ
��memset(a,'\0',sizeof(a))��

5.memcpy ����ԭ��void * memcpy(char *strDest, const char *strSrc, int Count)
memcpy�������ڴ濽�������Կ����κ��������͵Ķ��󣬿���ָ���������ݵĳ���
����char a[100],b[50]; memcpy(b, a, sizeof(b));ע������sizeof(a)�������b���ڴ��ַ����� 

6.strcpy��ֻ�ܿ����ַ����ˣ�������'\0'�ͽ�������������char a[100],b[50];strcpy(a,b);
����strcpy(b,a)��Ҫע��a�е��ַ������ȣ���һ����\0��֮ǰ���Ƿ񳬹�50λ���糬����������
b���ڴ��ַ�����

7.memset���Է�������һ���ṹ���͵ı��������顣
�����磺
����struct sample_struct
����{
����	  char csName[16];
����	  int iSeq;
����	  int iType;
����};

�������ڱ���
����struct sample_strcut stTest;
����һ������£����stTest�ķ�����
����stTest.csName[0]='\0';
����stTest.iSeq=0;
����stTest.iType=0;

������memset�ͷǳ����㣺
����memset(&stTest,0,sizeof(struct sample_struct));

������������飺
����struct sample_struct TEST[10];
������
����memset(TEST,0,sizeof(struct sample_struct)*10); 

8.  strcpy
	ԭ�ͣ�extern char *strcpy(char *dest,char *src);
�����÷�����include
�������ܣ���src��ָ��NULL�������ַ������Ƶ�dest��ָ�������С�
����˵����src��dest��ָ�ڴ����򲻿����ص���dest�������㹻�Ŀռ�������src���ַ�����
��������ָ��dest��ָ�롣

����memcpy
����ԭ�ͣ�extern void *memcpy(void *dest, void *src, unsigned int count);
�����÷�����include
�������ܣ���src��ָ�ڴ�������count���ֽڵ�dest��ָ�ڴ�����
����˵����src��dest��ָ�ڴ��������ص�����������ָ��dest��ָ�롣

����memset
����ԭ�ͣ�extern void *memset(void *buffer, int c, int count);
�����÷�����include
�������ܣ���buffer��ָ�ڴ������ǰcount���ֽ����ó��ַ�c��
����˵��������ָ��buffer��ָ�롣 
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
	char buffer[]="Hello World";//aΪ������ �ǵ�ַ ��ָ��   �Զ����Ͻ�������\0������a�й���12���ַ�
	char *s="Hello World";//sΪָ����� �ǵ�ַ

	printf("%s has %d chars\n",buffer,strlen(buffer));//11
	printf("%s has %d chars\n",s,strlen(s));//11
	printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("%s has %d bytes\n",buffer,sizeof(buffer));//12  bufferΪһ������ ���������������ֽ��� 
	printf("%s has %d bytes\n",s,sizeof(s));//4 sΪָ���ͱ���չ4���ֽ�
	printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");
#endif

#ifdef MEMSET_TEST
	char buffer[]="Hello World";//aΪ������ �ǵ�ַ ��ָ��   �Զ����Ͻ�������\0������a�й���12���ַ�
	char *s="Hello World";//sΪָ����� �ǵ�ַ

	printf("Buffer before memset: %s \n",buffer);
	memset(buffer,'*',strlen(buffer));
	printf("Buffer after memset: %s \n",buffer);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");

	memset(buffer,'A',5);
	printf("Buffer:%s \n",buffer);

	//�����кܴ�����������������в���ȥ�ˣ������sָ�����һ��ֻ�����ڴ棬
	//memset��ͼ�޸�������������ʱҪ�����޸İ취char *s�޸�Ϊchar s[]
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
	char str1[20]="I Love China";//�ַ��������Զ����Ͻ�����   I Love China ռ13���ֽڣ��������СΪ12ʱ���ø�ֵ��䲻�Ϸ� 
	//��Դ�ַ�������(������������)���ڵ��ڣ���Ϊ���Ҫ����һ����\0����Ŀ�ĵ�ַ��ָ����ڴ棨�ֽڣ�����ʱ���ᱨ����ʱ����
	//��Դ�ַ������ȴ���Ŀ���ַ�������ʱ���ᱨ����ʱ����
	char str2[]="You Love China";
	printf("%s\n",strcpya(str1,str2));

	//char *str3="I Love China";//����  ��Ϊstr3ָ�����һ��ֻ�����ڴ� ����s3[]
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