//约瑟夫环
//依次编号的n个人按顺时针顺序围坐，各持一个整数密码（无论正、负，不可为0）（人数与密码均由随机数生成，n<=30）
//任选报数界值m（由用户输入，自动规定|m|为上限，-|m|为下限）
// 展示每个人所持的密码
//若m为正整数，从第一个人开始按顺时针方向自1报数，报到m时停止，报m的人出列，将所持密码作为新的m值
//为负整数则第一个人按逆时针方向从-1开始报数
// 出列的人不参与后续报数,由其相邻的玩家开始报数（正顺逆负）
//输出所有人的出列顺序

//用顺序表实现

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define ERROR -1
#define PlayerMaxSize 20
#define OK 1


int main() {
	//获取界值
	printf("请输入报数界值（不可为0）：");
	int m = 0;
	scanf("%d", &m);
	//合法性判断
	if (!m) {
		printf("输入界值非法\n");
		return ERROR;
	}
	//上界
	int m1 = fabs(m);

	//设置游戏人员信息
	srand(time(NULL));
	int n = rand() % PlayerMaxSize + 1;
	int arr[PlayerMaxSize + 1];
	for (int i = 1; i <= n; i++) {
		arr[i] = rand() % m1 + 1;
		int sign = rand() % 2;
		if (sign == 1) {
			arr[i] = -1 * arr[i];
		}
	}

	//展示人员信息
	for (int i = 1; i <= n; i++) {
		printf("Player%-3dCode%d\n", i, arr[i]);
	}

	//进行游戏，已出列人员的密码重置为0
	printf("正确出列顺序应为：");

	int pointer = 1;//游戏进行时，指向报数人员

	for (int a = 0; a < n; a++) {//限制游戏只进行n轮
		int move = m % (n - a);
		int counter=0;

		if (move == 0) {
			if (m > 0) {
				if (arr[pointer] != 0) {
					counter++;
				}
				for (int i = 0; i < n; i++) {
					pointer--;
					if (pointer == 0) {
						pointer = n;
					}
					if (arr[pointer] != 0) {
						counter++;
					}
					if (counter == 2) {
						break;
					}
				}
			}

			if (m < 0) {
				if (arr[pointer] != 0) {
					counter++;
				}
				for (int i = 0; i < n; i++) {
					pointer++;
					if (pointer == n + 1) {
						pointer = 1;
					}
					if (arr[pointer] != 0) {
						counter++;
					}
					if (counter == 2) {
						break;
					}
				}
			}
		}


		if (move > 0) {
			if (arr[pointer] != 0) {
					move--;
			}
			for (; move!=0; ) {
				pointer++;
				if (pointer == n + 1) {
					pointer = 1;
				}
				if (arr[pointer] != 0) {
					move--;
				}
			}
		}

		if (move < 0) {
			if (arr[pointer] != 0) {
				move++;
			}
			for (; move != 0; ) {
				pointer--;
				if (pointer == 0) {
					pointer = n;
				}
				if (arr[pointer] != 0) {
					move++;
				}
			}
		}

		printf("%d ", pointer);
		m = arr[pointer];
		arr[pointer] = 0;
		counter = 0;
	}
	return 0;
}


	
	//int pointer = 0;
	//for (int a = 0; a < n; a++) {
	//	int move = m % (n - a);
	//	//m为n-a的倍数
	//	if (move == 0 &&m>0) {
	//		for (int i = 0; i < n; i++) {
	//			if (arr[pointer] != 0) {
	//				break;
	//			}
	//			else {
	//				pointer = (pointer + 1) % n;
	//			}
	//		}
	//		printf("%d ", pointer+1);
	//		m = arr[pointer];
	//		arr[pointer] = 0;
	//	}
	//	if (move == 0 && m < 0) {
	//		for (int i = 0; i < n; i++) {
	//			if (arr[pointer] != 0) {
	//				break;
	//			}
	//			else {
	//				pointer = (pointer +n-1) % n;
	//			}
	//		}
	//		printf("%d ", pointer + 1);
	//		m = arr[pointer];
	//		arr[pointer] = 0;
	//	}

	//	//m不为n-a的倍数
	//	if (move > 0) {
	//		int count = 0;
	//		for (int i = 0; count<move;i++) {
	//			int temp = arr[(pointer + i) % n];
	//			if (temp == 0)continue;
	//			count++;	
	//		}
	//		printf("%d ", pointer+1);
	//		m = arr[pointer];
	//		arr[pointer] = 0;
	//	}
	//	if (move < 0) {
	//		int count = 0;
	//		for (int i = 0; count > move; i++) {
	//			int temp = arr[(pointer - i+n) % n];
	//			if (temp == 0)continue;
	//			count--;
	//		}
	//		printf("%d ", pointer+1);
	//		m = arr[pointer];
	//		arr[pointer] = 0;
	//	}
	//}

	
	//	for (int a = 0; a < n; a++) {
//		int move = m % (n - a);
//		//m为n-a的倍数
//		if (move == 0 && m > 0) {
//			//出列
//			printf("%d  ", pointer->prior->num);
//			//新密码
//			m = pointer->prior->code;
//			//空间处理
//			tempp = pointer->prior->prior;
//			free(pointer->prior);
//			tempp->next = pointer;
//			pointer->prior = tempp;
//			//pointer不换位
//		}
//		if (move == 0 && m < 0) {
//			//出列
//			printf("%d  ", pointer->next->num);
//			//新密码
//			m = pointer->next->code;
//			//空间处理
//			tempp = pointer->next->next;
//			free(pointer->next);
//			tempp->prior = pointer;
//			pointer->next = tempp;
//			//pointer换位
//			pointer = pointer->next;
//		}
//
//		//m不为n-a的倍数
//		if (move > 0) {
//			//出列
//			for (int i = 1; i < move; i++) {
//				pointer = pointer->next;
//			}
//			printf("%d  ", pointer->num);
//			//新密码
//			m = pointer->code;
//			//空间处理&换位
//			tempp = pointer->prior;
//			pointer = pointer->next;
//			free(pointer->prior);
//			tempp->next = pointer;
//			pointer->prior = tempp;
//		}
//		if (move < 0) {
//			for (int i = -1; i > move; i--) {
//				pointer = pointer->prior;
//			}
//			printf("%d  ", pointer->num);
//			m = pointer->code;
//
//			tempp = pointer->next;
//			pointer = pointer->prior;
//			free(pointer->next);
//			tempp->prior = pointer;
//			pointer->next = tempp;
//		}
//	}


	
//struct player {
//	int num;
//	int code;
//	struct player* prior;
//	struct player* next;
//};
//
//typedef struct player P;
//
//void Reverse(P* head, int n);
////void Free(P* head, int n);
//
//int main() {
//	//获取界值
//	printf("请输入报数界值（不可为0）：");
//	int m = 0;
//	scanf("%d", &m);
//	//合法性判断
//	if (!m) {
//		printf("输入界值非法\n");
//		return ERROR;
//	}
//	//上界
//	int m1 = fabs(m);
//
//	//获取人员个数
//	srand(time(NULL));
//	int n = rand() % PlayerMaxSize + 1;
//
//	//生成游戏人员数据
//	//生成首元结点
//	P* head = (P*)malloc(sizeof(P));
//	head->num = 1;
//
//	srand(time(NULL));
//	//数位
//	int temp = rand() % m1 + 1;
//	//符号位，1为负，0为正
//	char sign = (char)(rand() % 2);
//	if (sign == 1) {
//		head->code = -1 * temp;
//	}
//	else {
//		head->code = temp;
//	}
//	head->prior = NULL;
//	head->next = NULL;
//
//	P* rear = head;
//
//	for (int i = 2; i <= n; i++) {
//		P* new = (P*)malloc(sizeof(P));
//		new->num = i;
//
//		//数位
//		int temp = rand() % m1 + 1;
//		//符号位，1为负，0为正
//		char sign = (char)(rand() % 2);
//		if (sign == 1) {
//			new->code = -1 * temp;
//		}
//		else {
//			new->code = temp;
//		}
//
//		new->prior = rear;
//		new->next = NULL;
//
//		rear->next = new;
//		rear = new;
//	}
//	rear->next = head;
//	head->prior = rear;
//
//	//展示人员信息
//	Reverse(head, n);
//
//	//进行游戏&打印编号&释放空间
//	printf("\n出列顺序为：");
//	P* pointer = head;
//	P* tempp = NULL;
//

//	return 0;
//}
//
//
//void Reverse(P* head, int n) {
//	P* p = head;
//	for (int i = 1; i <= n; i++) {
//		printf("Player%-3dCode  %d\n", p->num, p->code);
//		p = p->next;
//	}
//}
//
////void Free(P* head,int n) {
////	P* p1 = head;
////	P* p2 = p1->next;
////	for (int i = 1;i<=n; i++) {
////		free(p1);
////		p1 = p2;
////		p2 = p2->next;
////	}
////}