#include "head.h"
//参与者记录链表数组
LinkList ph[MAX] = { NULL };
//参观者记录链表数组
LinkList vh[MAX] = { NULL };
//参与者和参观者游玩次数记录
int par = 0;
int vis = 0;

//参与者历史记录
void Phis() {
	int i,t=0;
    printf("参与者模式：\n");
	if (par == 0) {
        printf(" ________________________________________________________________\n");
		printf("|您还未游玩过参与者模式，期待您的尝试！                          |\n");
        printf("|________________________________________________________________|\n");
		printf("输入任意键继续查询...\n");
		getchar();
	}
	else {
		LNode* p;
		for (i = 0; i < par; i++) {
            t = 0;
			p = ph[i];
            printf(" ________________________________________________________________\n");
            printf("|第%d局：\n|", i + 1);
            while (p->next != NULL) {
                p = p->next;
                printf("%d(%d)->", p->no, p->code);
                t++;
            }
            printf("\n|您第%d个被淘汰！\n", t);
            printf("|________________________________________________________________\n");
		}
        printf("输入任意键继续查询...\n");
        getchar();
	}
}
//参观者历史记录
void Vhis() {
    int i;
    printf("参观者模式：\n");
    if (vis == 0) {
        printf(" ________________________________________________________________\n");
        printf("|您还未游玩过参观者模式，期待您的尝试！                          |\n");
        printf("|________________________________________________________________|\n");
        printf("输入任意键返回主页面...\n");
        getchar();
    }
    else {
        LNode* v;
        for (i = 0; i < vis; i++) {
            v = vh[i];
            printf(" ________________________________________________________________\n");
            printf("|第%d局的淘汰链表：\n|", i + 1);
            while (v->next != NULL) {
                v = v->next;
                printf("%d(%d)->", v->no, v->code);
            }
            printf("NULL\n");
            printf("|________________________________________________________________|\n");
        }
        printf("输入任意键返回主页面...\n");
        getchar();
    }
}
//释放链表空间
void FreeList(LNode* p) {
    if (p == NULL) return;

    LNode* q= p->next;
    while (q != p) {
        LNode* t = q;
        q= q->next;
        free(t);
    }
    free(p);
}
//释放数组链表空间
void freepv() {
    int i;
    if (ph != NULL) {
        for (i = 0; i < par; i++) {
            FreeList(ph[i]);
        }
        free(ph);
    }
    if (vh!= NULL) {
        for (i = 0; i < vis; i++) {
            FreeList(vh[i]);
        }
        free(vh);
    }
}