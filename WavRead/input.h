#ifndef __INPUT_H__
#define __INPUT_H__

#include <stdio.h>
#include <stdlib.h>

#ifndef HAVE_INT32_T
typedef signed int int32_t;		//int32_tΪ�з���������4�ֽ�
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
  FILE *f;//�ļ��ṹ
  int channels;//ͨ����
  int samplebytes;//�����ֽ���
  int samplerate;//������ ������������ʾ
  int samples;  //��������
  int bigendian; //���ģʽ��
  int isfloat;  //
} PCM_FILE;//�Զ���pcm�ļ��ṹ

PCM_FILE *WavOpenRead(const char *path, int rawchans);//��ȡwav�ļ� 
size_t WavReadFloat32(PCM_FILE *sndf, float *buf, size_t num,int is_normalized);//size_t Ϊint�� ��ȡ
size_t WavReadInt24(PCM_FILE *sndf, int32_t *buf, size_t num/*, int *map*/);
int WavClose(PCM_FILE *file);//�ر�wav�ļ�

#ifdef __cplusplus
}
#endif
#endif
