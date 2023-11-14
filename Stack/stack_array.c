
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable : 4996)

//메뉴 switch case문 쓰려고 enum으로해서 해주기.
enum what {
	PUSH=1, POP, PRINT, CLEAR, HOW, EMPTY, EXIT=0
};		//size라는 대문자 변수가 사용이 안되어서 그냥 HOW로 썼다.


//배열 사이즈 선언.
#define MAX_SIZE 5


//스택 구조체 선언
typedef struct stk{
	int top;
	int arr[MAX_SIZE];
}stck;


void Create_Stack(stck* p);	//처음 pop을 -1로 초기화해주기 위한 함수
void Push(stck* p, int num);	//Push하려는 함수
int Pop(stck* p);	//Pop하려는 함수
void Print_Stack(stck* p); //Top값을 print하는 함수
void Clear(stck* p); //스택의 모든 값을 clear.
void How(stck* p); //남아있는 스택의 size.
void Empty(stck* p); //스택이 하나라도 있으면 1 , 아니면 0


int main()
{
	int choice;
	int value;
	stck stk;		//구조체 변수 선언.
	Create_Stack(&stk);	//처음 스택 초기화.
	while (1)
	{
		system("cls");
		printf("\n\n\t\t*** Stack with Array ***\n");
		printf("\t\t1. PUSH    2. POP    3. PRINT    4. CLEAR    5. SIZE    6. EMPTY?    0. EXIT\n");
		printf("\t\tchoice : [ ]\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');
		printf("\n");
		switch (choice)
		{
			case PUSH:
				printf("\t\tPUSH할 값을 입력해주세요 :");
				scanf("%d", &value);
				while (getchar() != '\n');
				Push(&stk, value);
				break;

			case POP:
				Pop(&stk);
				break;

			case PRINT:
				Print_Stack(&stk);
				break;

			case CLEAR:
				Clear(&stk);
				break;

			case HOW:
				How(&stk);
				break;

			case EMPTY: 
				Empty(&stk);
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

//처음 스택 초기화
void Create_Stack(stck* p)
{
	p->top = -1;
}


void Push(stck* p, int num)
{
	(p->top)++;
	p->arr[p->top] = num;
	if ((p->top) > MAX_SIZE-1)
	{
		(p->top)--;	//위에서 증가한 top값을 다시 max값인 4로 만들어주기 위해서.
		printf("\t\t값을 넣으면 Over Flow가 일어나서 값을 넣을 수 없습니다.\n");
		Sleep(500);
		return;
	}
	printf("\t\tPush에 성공했습니다.\n");
	printf("\n\n\t\tp->top : %d", p->top);
	Sleep(500);
	return;
}

int Pop(stck* p)
{
	(p->top)--;
	if ((p->top) < -1)
	{
		(p->top)++;	//위에서 감소한 top값을 다시 돌려주기 위해서.
		printf("\t\t더 시도하면 Under Flow가 일어나서 값을 뺄 수 없습니다.\n");
		Sleep(500);
		return 0;
	}
	else if ((p->top) == -1)
	{
		printf("\t\t모든 스택을 Pop 했습니다.\n");
		printf("\n\n\t\tp->top : %d\n", p->top);
		Sleep(500);
		return 1;
	}
	printf("\t\t%d값을 Pop했습니다.\n",p->arr[(p->top)+1]);		//위에서 감소해서 p->top에 하나를 더해준다.
	printf("\t\tp->top : %d", (p->top)+1);
	Sleep(500);
	return p->arr[p->top];
}

void Print_Stack(stck* p)
{
	if (p->top == -1)
	{
		printf("\t\t아무것도 생성되지 않았습니다.\n");
		Sleep(500);
		return;
	}
	printf("\t\tTOP값은 %d입니다.\n",p->arr[p->top] );
	Sleep(500);
	return;
}

void Clear(stck* p)
{
	if (p->top == -1)
	{
		printf("\t\t이미 비워져 있습니다.\n");
		Sleep(500);
		return;
	}
	p->top = -1;
	printf("\t\t모든 스택을 Clear 했습니다.\n");
	return;
}

void How(stck* p)
{
	printf("\t\tStack의 size는 %d입니다.\n", (p->top) + 1);
	Sleep(500);
	return;
}

void Empty(stck* p)
{
	if ((p->top) > -1)
	{
		printf("\t\t1, True\n");
		Sleep(500);
		return;
	}
	else
	{
		printf("\t\t0, False");
		Sleep(500);
		return;
	}
}
