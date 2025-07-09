#ifndef _HEAD_
#define _HEAD_
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#define MAX 100
//定义约瑟夫结构体
typedef struct LNode {
	int no;
	int code;
	struct LNode* next;
}LNode, * LinkList;
//声明全局变量
extern LinkList ph[MAX];
extern LinkList vh[MAX];
extern int par;
extern int vis;
//页面函数
int page();
void pagev(int& i);
//参与者模式数据建立和游戏进行函数
void PData(int& n, int& m, int& myno, int& mym);
void Pgame(int n, int m, int myno, int mym);
//参观者模式数据建立和游戏进行函数
void VData(int &n,int &m);
void Vgame(int n, int m);
//游戏历史数据进行和释放空间函数
void Phis();
void Vhis();
void FreeList(LNode* head);
void freepv();
#endif // !_MY_HEAD_
