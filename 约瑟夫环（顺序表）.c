//Լɪ��
//���α�ŵ�n���˰�˳ʱ��˳��Χ��������һ���������루����������������Ϊ0�������������������������ɣ�n<=30��
//��ѡ������ֵm�����û����룬�Զ��涨|m|Ϊ���ޣ�-|m|Ϊ���ޣ�
// չʾÿ�������ֵ�����
//��mΪ���������ӵ�һ���˿�ʼ��˳ʱ�뷽����1����������mʱֹͣ����m���˳��У�������������Ϊ�µ�mֵ
//Ϊ���������һ���˰���ʱ�뷽���-1��ʼ����
// ���е��˲������������,�������ڵ���ҿ�ʼ��������˳�渺��
//��������˵ĳ���˳��

//��˳���ʵ��

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define ERROR -1
#define PlayerMaxSize 20
#define OK 1


int main() {
	//��ȡ��ֵ
	printf("�����뱨����ֵ������Ϊ0����");
	int m = 0;
	scanf("%d", &m);
	//�Ϸ����ж�
	if (!m) {
		printf("�����ֵ�Ƿ�\n");
		return ERROR;
	}
	//�Ͻ�
	int m1 = fabs(m);

	//������Ϸ��Ա��Ϣ
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

	//չʾ��Ա��Ϣ
	for (int i = 1; i <= n; i++) {
		printf("Player%-3dCode%d\n", i, arr[i]);
	}

	//������Ϸ���ѳ�����Ա����������Ϊ0
	printf("��ȷ����˳��ӦΪ��");

	int pointer = 1;//��Ϸ����ʱ��ָ������Ա

	for (int a = 0; a < n; a++) {//������Ϸֻ����n��
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
	//	//mΪn-a�ı���
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

	//	//m��Ϊn-a�ı���
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
//		//mΪn-a�ı���
//		if (move == 0 && m > 0) {
//			//����
//			printf("%d  ", pointer->prior->num);
//			//������
//			m = pointer->prior->code;
//			//�ռ䴦��
//			tempp = pointer->prior->prior;
//			free(pointer->prior);
//			tempp->next = pointer;
//			pointer->prior = tempp;
//			//pointer����λ
//		}
//		if (move == 0 && m < 0) {
//			//����
//			printf("%d  ", pointer->next->num);
//			//������
//			m = pointer->next->code;
//			//�ռ䴦��
//			tempp = pointer->next->next;
//			free(pointer->next);
//			tempp->prior = pointer;
//			pointer->next = tempp;
//			//pointer��λ
//			pointer = pointer->next;
//		}
//
//		//m��Ϊn-a�ı���
//		if (move > 0) {
//			//����
//			for (int i = 1; i < move; i++) {
//				pointer = pointer->next;
//			}
//			printf("%d  ", pointer->num);
//			//������
//			m = pointer->code;
//			//�ռ䴦��&��λ
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
//	//��ȡ��ֵ
//	printf("�����뱨����ֵ������Ϊ0����");
//	int m = 0;
//	scanf("%d", &m);
//	//�Ϸ����ж�
//	if (!m) {
//		printf("�����ֵ�Ƿ�\n");
//		return ERROR;
//	}
//	//�Ͻ�
//	int m1 = fabs(m);
//
//	//��ȡ��Ա����
//	srand(time(NULL));
//	int n = rand() % PlayerMaxSize + 1;
//
//	//������Ϸ��Ա����
//	//������Ԫ���
//	P* head = (P*)malloc(sizeof(P));
//	head->num = 1;
//
//	srand(time(NULL));
//	//��λ
//	int temp = rand() % m1 + 1;
//	//����λ��1Ϊ����0Ϊ��
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
//		//��λ
//		int temp = rand() % m1 + 1;
//		//����λ��1Ϊ����0Ϊ��
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
//	//չʾ��Ա��Ϣ
//	Reverse(head, n);
//
//	//������Ϸ&��ӡ���&�ͷſռ�
//	printf("\n����˳��Ϊ��");
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