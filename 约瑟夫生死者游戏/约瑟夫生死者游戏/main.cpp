#include"head.h"
int main() {
	int pat,n,m;
	int myno, mym;
	do{
		pat = page();
		switch (pat)
		{
		case 1: {//参与者模式
			PData(n, m, myno, mym);//建立数据
			Pgame(n, m, myno, mym);//进行游戏
			par++;
			break;
		}
		case 2: {//参观者模式
			VData(n,m);//建立数据
			Vgame(n, m);//进行游戏
			vis++;
			break;
		}
		case 3: {//历史记录
			Phis();//参与者历史记录
			Vhis();//参观者历史记录
		}
		default:
			break;
		}
	} while (pat != 0);//退出
	printf("感谢游玩！\n");
	void freepv();//释放数组链表空间
	return 0;
}