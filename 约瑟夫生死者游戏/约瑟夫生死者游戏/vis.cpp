#include"head.h"
//参观者模式数据建立
void VData(int &n,int &m) {
	int t,i;
	do {//人数
		printf(" ________________________________________________________________\n");
		printf("|参观者模式->\n");
		printf("|请您决定参与游戏人数n（0<n<=30)\n");
		printf("|________________________________________________________________\n");
		printf("请选择人数:\n");
		scanf("%d", &n);
	} while (!(n > 0 && n <= 30));
	do {//报数
		printf(" ________________________________________________________________\n");
		printf("|参观者模式->人数%d->\n", n);
		printf("|请您决定初始报数上限m（0<m<=%d)\n", n);
		printf("|________________________________________________________________\n");
		printf("请选择初始报数上限:\n");
		scanf("%d", &m);
	} while (!(m > 0 && m <= n));
}
//参观者游戏进行
void Vgame(int n, int m) {
	int t=0,i,j;
	srand((unsigned)time(NULL));
	//创建循环链表
	LNode* head = (LNode*)malloc(sizeof(LNode));
	if (!head)exit(EXIT_FAILURE);
	head->next = NULL;
	LNode* tail = head;

	pagev(t);//判断手动输入或系统随机
	if (t == 1) {
		for (i = 0; i < n; i++) {
			LNode* q = (LNode*)malloc(sizeof(LNode));
			if (!q)exit(EXIT_FAILURE);
			printf("请输入编号%d的密码：\n", i + 1);
			scanf("%d", &(q->code));
			q->no = i + 1;
			q->next = NULL;
			tail->next = q;
			tail = q;
		}
	}
	else {
		for (i = 0; i < n; i++) {
			LNode* q = (LNode*)malloc(sizeof(LNode));
			if (!q)exit(EXIT_FAILURE);
			q->code = rand() % n + 1;
			q->no = i + 1;
			q->next = NULL;
			tail->next = q;
			tail = q;
		}
	}
	tail->next = head->next;//循环链表
	//初始化淘汰链表
	vh[vis] = (LNode*)malloc(sizeof(LNode));//记录链头节点
	if (!vh[vis])exit(EXIT_FAILURE);
	vh[vis]->next = NULL;
	LNode* r = vh[vis];

	//游戏逻辑
	LNode* c = head->next;
	LNode* prev =tail;//初始指向头节点
	i = 0;
	j = m; 

	printf(" ________________________________________________________________\n");
	printf("|参观者模式->人数%d->初始报数上限%d->\n", n, m);
	printf("|淘汰顺序表为：\n|");
	while (i < n ) {
		if (j == 1) {
			i++;
			
			//记录淘汰者
			LNode*p = (LNode*)malloc(sizeof(LNode));
			if (!p)exit(EXIT_FAILURE);
			p->no = c->no;
			p->code = c->code;
			p->next = NULL;

			r->next = p;
			r = p;

			printf("%d(%d)->", c->no, c->code);
			prev->next = c->next;
			j = c->code;
			free(c);  // 释放淘汰节点
			c = prev->next;
		}
		else {
			prev = c;
			c = c->next;
			j--;
		}
	}

	// 释放游戏链表
	prev->next = NULL;  // 断开循环
	free(head);

	printf("NULL\n|________________________________________________________________\n");
	printf("输入任意键重新开始游戏...\n");
	while (getchar() != '\n');
	getchar();
}