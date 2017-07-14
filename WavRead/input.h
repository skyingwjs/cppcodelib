#ifndef __INPUT_H__
#define __INPUT_H__

#include <stdio.h>
#include <stdlib.h>

#ifndef HAVE_INT32_T
typedef signed int int32_t;		//int32_t为有符号整型数4字节
#endif
#ifndef HAVE_INT16_T
typedef signed short int16_t;
#endif
#ifndef HAVE_U_INT32_T
typedef unsigned int u_int32_t;
#endif
#ifndef HAVE_U_INT16_T
typedef unsigned short u_int16_t;
#endif


#ifdef __cplusplus
	extern "C"{
#endif

typedef struct
{
  FILE *f;//文件结构
  int channels;//通道数
  int samplebytes;//样本字节数
  int samplerate;//采样率 由索引号来表示
  int samples;  //样本个数
  int bigendian; //大端模式？
  int isfloat;  //
} PCM_FILE;//自定义pcm文件结构

PCM_FILE *WavOpenRead(const char *path, int rawchans);//读取wav文件 
size_t WavReadFloat32(PCM_FILE *sndf, float *buf, size_t num,int is_normalized);//size_t 为int型 读取
size_t WavReadInt24(PCM_FILE *sndf, int32_t *buf, size_t num/*, int *map*/);
int WavClose(PCM_FILE *file);//关闭wav文件

#ifdef __cplusplus
}
#endif
#endif
