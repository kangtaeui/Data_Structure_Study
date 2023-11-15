//queue_array 강태의
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma warning (disable : 4996)


enum what {
	PUSH = 1, POP, PRINT, BULK, CLEAR, EMPTY, EXIT = 0
};
typedef struct queue
{
	int* data;		//동적할당된 메모리의 주소를 저장하는 포인터(8바이트)
	int rear;		//삽입할 배열의 인덱스
	int front;		//삭제할 배열의 인덱스
	int size;		//배열에 저장된 원소의 개수
	int capacity;	//배열의 최대 용량(배열의 크기)
}queue;

void createQueue(queue* q, int count);
void enQueue(queue* q);
int deQueue(queue* q);
int quePrint(queue* q);
int quesize(queue* q);
void que_Clear(queue* q);
int empty(queue* q);

int main()
{
	queue que; //구조체 변수 선언(24바이트)
	int choice, count, value;

	printf("할당하고 싶은 큐의 크기를 입력 하세요 : ");
	scanf("%d", &count);
	while (getchar() != '\n');

	createQueue(&que, count);

	while (1)
	{
		system("cls");
		printf("\n\n\t\t****  배열을 이용한 원형 큐 ***\n\n");
		printf("1. push    2. pop    3. print    4. size     5. clear	  6.empty   7.exit\n");
		printf("choice : [ ]\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case PUSH:
			enQueue(&que);
			break;
		case POP:
			deQueue(&que);
			break;
		case PRINT:
			quePrint(&que);
			break;
		case BULK:
			quesize(&que);
			break;
		case CLEAR:
			que_Clear(&que);
			break;
		case EMPTY:
			queEmpty(&que);
			break;
		case EXIT:
			return 0;
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

void createQueue(queue* q, int count)
{
	q->data = (int*)malloc(sizeof(int) *count);		//입력받은 count만큼 메모리 동적할당
	q->rear = 0;
	q->front = 0;
	q->size = 0;
	q->capacity = count;

	return;
}

void enQueue(queue* q)
{
	int value;
	if (q->capacity == q->size)
	{
		printf("\n\n\t\tqueue가 꽉찼습니다. 더이상 시도하면 Over Flow입니다.\n");
		Sleep(500);
		return;
	}
	
	printf("\n\n\t\tpush/enqueue하고싶은 value값을 입력하세요 :");
	scanf("%d", &value);
	while (getchar() != '\n');
	q->data[q->rear] = value;
	q->rear++;
	q->size++;
	printf("\t\t삽입이 완료되었습니다.\n");
	Sleep(500);
	return;
}

int deQueue(queue* q)
{
	if (q->size == 0)
	{
		printf("\n\n\t\t더이상 시도하면 Under Flow입니다.\n");
		Sleep(500);
		return -1;
	}
	
	printf("%d값이 pop되었습니다.", q->data[q->front]);
	q->front++;
	q->size--;

	return q->data[q->front];
}

int quePrint(queue* q)
{
	int i;
	if (q->size == 0)
	{
		printf("\n\n\t\t출력할 queue가 없습니다.\n");
		Sleep(500);
		return;
	}
	for (i = q->front; i < q->rear - 1; i++)
	{
		printf("%d <-", q->data[i]);
	}
	printf("%d", q->data[q->rear-1]);
	Sleep(500);
	return q->data[q->rear];
}

int quesize(queue* q)
{
	printf("\n\n\t\t queue의 현재 사이즈 : %d", q->size);
	Sleep(500);
	return q->size;
}

void que_Clear(queue* q)
{
	q->front = 0;
	q->rear = 0;
	q->size = 0;
	printf("\n\n\t\tQueue를 Clear하였습니다.\n");
	Sleep(500);
	return;
}
int queEmpty(queue* q)
{
	if (q->size != 0)
	{
		printf("\n\n\t\t not empty");
		Sleep(500);
		return 1;
	}
	printf("\n\n\t\t empty");
	Sleep(500);
	return 1;
}
