//Լɪ��
//���α�ŵ�n���˰�˳ʱ��˳��Χ��������һ���������루����������������Ϊ0�������������������������ɣ�n<=30��
//��ѡ������ֵm�����û����룬�Զ��涨|m|Ϊ���ޣ�-|m|Ϊ���ޣ�
// չʾÿ�������ֵ�����
//��mΪ���������ӵ�һ���˿�ʼ��˳ʱ�뷽����1����������mʱֹͣ����m���˳��У�������������Ϊ�µ�mֵ
//Ϊ���������һ���˰���ʱ�뷽���-1��ʼ����
// ���е��˲������������,�������ڵ���ҿ�ʼ��������˳�渺��
//��������˵ĳ���˳��

//��ѭ������ʵ��

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define ERROR -1
#define PlayerMaxSize 30
#define OK 1

struct player {
	int num;
	int code;
	struct player* prior;
	struct player* next;
};

typedef struct player P;

void Reverse(P* head,int n);
//void Free(P* head, int n);

int main(){
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

	//��ȡ��Ա����
	srand(time(NULL));
	int n = rand() % PlayerMaxSize + 1;

	//������Ϸ��Ա����
	//������Ԫ���
	P* head = (P*)malloc(sizeof(P));
	head->num = 1;

	srand(time(NULL));
	//��λ
	int temp = rand() % m1 + 1;
	//����λ��1Ϊ����0Ϊ��
	char sign = (char)(rand() % 2);
	if (sign == 1) {
		head->code = -1 * temp;
	}
	else {
		head->code = temp;
	}
	head->prior = NULL;
	head->next = NULL;

	P* rear = head;
	
	for (int i = 2; i <= n; i++) {
		P* new = (P*)malloc(sizeof(P));
		new->num = i;

		//��λ
		int temp = rand() % m1 + 1;
		//����λ��1Ϊ����0Ϊ��
		char sign = (char)(rand() % 2);
		if (sign == 1) {
			new->code = -1 * temp;
		}
		else {
			new->code = temp;
		}
		
		new->prior = rear;
		new->next = NULL;

		rear->next = new;
		rear = new;
	}
	rear->next = head;
	head->prior = rear;

	//չʾ��Ա��Ϣ
	Reverse(head,n);

	//������Ϸ&��ӡ���&�ͷſռ�
	printf("\n����˳��Ϊ��");
	P* pointer = head;
	P* tempp = NULL;

	for (int a = 0; a < n; a++) {
		int move = m % (n - a);
		//mΪn-a�ı���
		if (move == 0 && m > 0) {
			//����
			printf("%d  ", pointer->prior->num);
			//������
			m = pointer->prior->code;
			//�ռ䴦��
			tempp = pointer->prior->prior;
			free(pointer->prior);
			tempp->next = pointer;
			pointer->prior = tempp;
			//pointer����λ
		}
		if (move == 0 && m < 0) {
			//����
			printf("%d  ", pointer->next->num);
			//������
			m = pointer->next->code;
			//�ռ䴦��
			tempp = pointer->next->next;
			free(pointer->next);
			tempp->prior = pointer;
			pointer->next = tempp;
			//pointer��λ
			pointer = pointer->next;
		}

		//m��Ϊn-a�ı���
		if (move > 0) {
			//����
			for (int i = 1; i < move; i++) {
				pointer = pointer->next;
			}
			printf("%d  ", pointer->num);
			//������
			m = pointer->code;
			//�ռ䴦��&��λ
			tempp = pointer->prior;
			pointer = pointer->next;
			free(pointer->prior);
			tempp->next = pointer;
			pointer->prior = tempp;
		}
		if (move < 0) {
			for (int i = -1; i > move; i--) {
				pointer = pointer->prior;
			}
			printf("%d  ", pointer->num);
			m = pointer->code;

			tempp = pointer->prior;
			pointer = pointer->next;
			free(pointer->prior);
			tempp->next = pointer;
			pointer->prior = tempp;
		}

		if (m < 0) {
			pointer = pointer->prior;
		}
	}
	return 0;
}


void Reverse(P* head,int n) {
	P* p = head;
	for(int i=1;i<=n;i++) {
		printf("Player%-3dCode  %d\n", p->num,p->code);
		p = p->next;
	}
}

//void Free(P* head,int n) {
//	P* p1 = head;
//	P* p2 = p1->next;
//	for (int i = 1;i<=n; i++) {
//		free(p1);
//		p1 = p2;
//		p2 = p2->next;
//	}
//}