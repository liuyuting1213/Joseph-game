#ifndef _HEAD_
#define _HEAD_
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#define MAX 100
//����Լɪ��ṹ��
typedef struct LNode {
	int no;
	int code;
	struct LNode* next;
}LNode, * LinkList;
//����ȫ�ֱ���
extern LinkList ph[MAX];
extern LinkList vh[MAX];
extern int par;
extern int vis;
//ҳ�溯��
int page();
void pagev(int& i);
//������ģʽ���ݽ�������Ϸ���к���
void PData(int& n, int& m, int& myno, int& mym);
void Pgame(int n, int m, int myno, int mym);
//�ι���ģʽ���ݽ�������Ϸ���к���
void VData(int &n,int &m);
void Vgame(int n, int m);
//��Ϸ��ʷ���ݽ��к��ͷſռ亯��
void Phis();
void Vhis();
void FreeList(LNode* head);
void freepv();
#endif // !_MY_HEAD_
