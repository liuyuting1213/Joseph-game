#include"head.h"
//参与者模式数据收集
void PData(int& n, int& m, int& myno, int& mym) {
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
	do {//自己的编号，密码
		printf(" ________________________________________________________________\n");
		printf("|参观者模式->人数%d->初始报数上限%d->\n", n, m);
		printf("|请决定您的编号和密码（0-%d）\n", n);
		printf("|________________________________________________________________\n");
		printf("请选择您的编号:\n");
		scanf("%d", &myno);
		printf("请选择您的密码:\n");
		scanf("%d", &mym);
		while (getchar() != '\n');
	} while (!(myno > 0 && myno <= n && mym > 0 && mym <= n));
}
//参与者游戏进行
void Pgame(int n, int m, int myno, int mym) {
    int i, j;
    srand((unsigned)time(NULL));

    //  创建循环链表
    LNode* head = (LNode*)malloc(sizeof(LNode));  // 头节点
    if (!head) exit(EXIT_FAILURE);
    head->next = NULL;
    LNode* tail = head;

    for (i = 1; i <= n; i++) {
        LNode* q = (LNode*)malloc(sizeof(LNode));
        if (!q) exit(EXIT_FAILURE);

        q->no = i;
        q->code = (i == myno) ? mym : rand() % n + 1;
        q->next = NULL;

        tail->next = q;
        tail = q;
    }
    tail->next = head->next;  // 循环闭合

    // 初始化淘汰记录链表
    ph[par] = (LNode*)malloc(sizeof(LNode));  // 记录链表头节点
    if (!ph[par]) exit(EXIT_FAILURE);
    ph[par]->next = NULL;
    LNode* r = ph[par];

    // 游戏逻辑
    LNode* c= head->next;
    LNode* prev =tail;  
    i = 0;
    j = m;

    while (i < n - 1) {
        if (j == 1) {
            i++;
            // 记录淘汰者
            LNode* p = (LNode*)malloc(sizeof(LNode));
            if (!p) exit(EXIT_FAILURE);
            p->no = c->no;
            p->code = c->code;
            p->next = NULL;

            r->next = p;
            r =p;

            printf(" ________________________________________________________________\n");
            printf("|参观者模式->人数%d->初始报数上限%d->您的编号为%d密码为%d\n", n, m,myno,mym);
            printf("|编号%d淘汰，密码%d\n", c->no, c->code);

            if (c->no == myno) {
                printf("|您第%d个被淘汰，游戏结束！\n", i);
                //释放剩余链表
                FreeList(c); 
                printf("|________________________________________________________________\n");
                printf("输入任意键重新开始游戏...\n");
                getchar();
                return;  // 直接退出函数
            }
            else {
                printf("|剩余人数%d人,游戏继续!\n",n-i);
                printf("|________________________________________________________________\n");
                printf("输入任意键继续...\n");
                getchar();
                // 移除当前节点
                prev->next = c->next;
                j = c->code;
                free(c);  // 释放淘汰节点
                c = prev->next;
            }
        }
        else {
            prev = c;
            c= c->next;
            j--;
        }
    }

    // 记录最后一名
    LNode* p = (LNode*)malloc(sizeof(LNode));
    if (!p)exit(EXIT_FAILURE);
        p->no = c->no;
        p->code = c->code;
        p->next = NULL;
        r->next = p;

    // 释放游戏链表
    free(c);
    head->next = NULL;
    free(head);

    printf(" ________________________________________________________________\n");
    printf("|                     恭喜您活到最后！！！\n");
    printf("|________________________________________________________________\n");
    printf("输入任意键重新开始游戏...\n");
    getchar();
}