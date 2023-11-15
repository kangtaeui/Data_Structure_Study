//queue_list

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable : 4996)

//메뉴 switch case문 쓰려고 enum으로해서 해주기.
enum what {
	PUSH = 1, POP, PRINT, CLEAR, BULK, EMPTY, EXIT = 0
};		//size라는 대문자 변수가 사용이 안되어서 그냥 HOW로 썼다.


//큐 구조체 선언
typedef struct que{
	int value;
	struct que* next;
	struct que* prev;
	
}que;

que* head = NULL;
que* tail = NULL;
int size = 0;


que* create_Q(int how);
void Push();
int Pop();
int Print();
void Clear();
int Size();
void Empty();


int main()
{
	int choice;
	que qu;		//구조체 변수 선언.
	while (1)
	{


		system("cls");
		printf("\n\n\t\t*** Stack with List ***\n");
		printf("\t\t1. PUSH    2. POP    3. PRINT    4. CLEAR    5. SIZE    6. EMPTY?    0. EXIT\n");
		printf("\t\tchoice : [ ]\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');
		printf("\n");
		switch (choice)
		{
		case PUSH:
			Push();
			break;

		case POP:
			Pop();
			break;

		case PRINT:
			Print();
			break;

		case CLEAR:
			Clear();
			break;

		case BULK:
			Size();
			break;

		case EMPTY:
			Empty();
			break;

		case EXIT:
			printf("종료하겠습니다...");
			Sleep(500);
			return;
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

que* create_Q()
{
	que* newNode;
	newNode = (que*)malloc(sizeof(que));
	printf("\t\tvalue값을 입력해주세요 :");
	scanf("%d", &newNode->value);
	while (getchar() != '\n');
	newNode -> next = NULL;
	newNode -> prev = NULL;
	
	return newNode;
}

void Push()
{
	que* newNode;
	printf("\n\n\t\tPUSH/ENQUEUE를 진행하겠습니다.\n");
	newNode = create_Q();
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
		printf("\t\tPUSH/ENQUEUE를 완료했습니다.\n");
		printf("\t\t1");
		Sleep(500);
		size++;
		return;
	}
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	printf("\n\t\tPUSH/ENQUEUE를 완료했습니다.\n");
	size++;
	return;	
}

int Pop()
{
	que* delNode;
	if (head == NULL)
	{
		printf("\n\n\t\t삭제할 데이터가 없습니다.\n");
		Sleep(500);
		return 0;
	}
	int data = head->value;
	delNode = head;
	head = head->next;
	free(delNode);
	//삭제하고 난 후
	if (head != NULL)
	{
		size--;
		head->prev = NULL;
		printf("\n\n\t\t데이터값 %d를 POP/DEQUEUE 했습니다.\n", data);
		Sleep(500);
		return data;
	}
	if (head == NULL)
	{
		size--;
		tail = NULL;
		printf("\n\n\t\t데이터값 %d를 POP/DEQUEUE 했습니다.\n", data);
		printf("\n\n\t\t데이터를 모두 DEQUEUE/POP했습니다.\n");
		Sleep(500);
		return data;
	}
}

int Print() //고치면 끝
{
	que* curNode;
	curNode = head;
	if (head == NULL)
	{
		printf("\n\n\t\t출력할 데이터가 없습니다.\n");
		Sleep(500);
		return 1;
	}
	if (size == 1)
	{
		printf("\n\n\t\t%d", curNode->value);
		return curNode->value;
	}
	printf("\n\n\t\t");
	while (curNode->next != NULL)
	{
		printf("%d <-", curNode->value);
		curNode = curNode->next;

	}
	printf("%d", curNode->value);
	Sleep(500);
	return curNode->value;
}

void Clear()
{
	if (head == NULL)
	{
		printf("\n\n\t\tqueue가 이미 비워져있습니다.\n");
		Sleep(500);
		return;
	}
	que* delNode;
	while (head->next != NULL)
	{
		delNode = head;		//헤드값 넣고
		head = head->next;	//헤드값 넥스트로 옮기고
		free(delNode);		//delNode에 들어있는 head값 삭제
	}
	size = 0;
	head = NULL;
	tail = NULL;
	printf("\n\n\t\tqueue를 clear하였습니다.\n");
	return;
}

int Size()
{
	printf("\n\n\t\tqueue의 size : %d\n", size);
	Sleep(500);
	return;
}

void Empty()
{
	if (size == 0)
	{
		printf("\n\n\t\tempty\n");
		Sleep(500);
	}
	else
	{
		printf("\n\n\t\tnot empty\n");
		Sleep(500);
	}
}
