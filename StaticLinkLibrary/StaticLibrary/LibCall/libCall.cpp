#include <stdio.h>
#include <stdlib.h>
#include "..\\StaticLibrary\\lib.h"
#pragma comment( lib, "..\\debug\\StaticLibrary.lib" )//指定与静态库一起连接
int main(int argc, char* argv[])
{
 if (3 == argc)
  printf( "%d + %d = %d", atoi(argv[1]), atoi(argv[2]) ,add( atoi(argv[1]), atoi(argv[2]) ) );
 else
  printf( "error,input format: libCall num1 num2");
 system("pause");
} 