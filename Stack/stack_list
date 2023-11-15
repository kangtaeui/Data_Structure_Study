//stack with list_강태의
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable : 4996)

//메뉴 switch case문 쓰려고 enum으로해서 해주기.
enum what {
	PUSH = 1, POP, PRINT, CLEAR, HOW, EMPTY, EXIT = 0
};		//size라는 대문자 변수가 사용이 안되어서 그냥 HOW로 썼다.


//스택 구조체 선언
typedef struct stck {
	int value;
	struct stck* next;
}stck;

int top_cnt = -1;
void Push();	//Push하려는 함수
int Pop();	//Pop하려는 함수
int Print_Stack(); //Top값을 print하는 함수
int Clear(); //스택의 모든 값을 clear.
void How(); //남아있는 스택의 size.
void Empty(); //스택이 하나라도 있으면 1 , 아니면 0

stck* head = NULL;

int main()
{
	int choice;
	stck stk;		//구조체 변수 선언.
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
			Print_Stack();
			break;

		case CLEAR:
			Clear();
			break;

		case HOW:
			How();
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

void Push()
{
	stck* Push_stk;	//newNode;
	Push_stk = (stck*)malloc(sizeof(stck));
	printf("\t\tPush하려는 값을 입력해주세요 : ");
	scanf("%d", &Push_stk->value);
	while (getchar() != '\n');
	Push_stk->next = NULL;

	if (head == NULL)	//아무것도 없을 때
	{
		head = Push_stk;
		printf("\t\tPush에 성공하였습니다.");
		top_cnt++;
		printf("\n\n\t\ttop -> %d\n", top_cnt);
		Sleep(500);
		return;
	}
	top_cnt++;
	if (top_cnt > 4)
	{
		printf("\t\t더이상 Push를 시도하면 Over Flow가 일어납니다.\n");
		top_cnt = 4;
		Sleep(500);
		return;
	}

	Push_stk->next = head;
	head = Push_stk;
	printf("\t\tPush에 성공하였습니다.");

	printf("\n\n\t\ttop -> %d\n", top_cnt);

	return;
}

int Pop()
{
	int Pop_Num;
	stck* Cur_stk;	//delNode;
	Cur_stk = head;
	if (head == NULL)
	{
		printf("\t\t더이상 Pop을 시도하면 Under Flow가 발생합니다.\n");
		Sleep(500);
		return top_cnt;
	}
	head = head->next;
	Pop_Num = Cur_stk->value;
	free(Cur_stk);
	printf("\t\t%d값을 Pop 했습니다.", Pop_Num);
	printf("\n\n\t\ttop -> %d\n", top_cnt);
	top_cnt--;
	Sleep(500);
	return Pop_Num;
}

int Print_Stack()
{
	if (head == NULL)
	{
		printf("\n\n\t\tStack이 비어있습니다.");
		Sleep(500);
		return;
	}

	int top_num;
	stck* Cur_stk;
	Cur_stk = head;
	top_num = Cur_stk->value;
	printf("\n\n\t\ttop -> value : %d\n", top_num);
	Sleep(500);
	return top_num;
}

int Clear()
{
	stck* clear_stk;
	if (head == NULL)
	{
		printf("\t\t삭제할 Stack이 없습니다\n");
		return 1;
	}
	while (head != NULL)
	{
		clear_stk = head;
		head = head->next;
		free(clear_stk);
	}
	top_cnt = -1;
	printf("\t\tClear를 실행했습니다.\n");
	return top_cnt;
}


void How()
{
	printf("\t\tStack의 size : %d입니다.", top_cnt + 1);
	Sleep(500);
	return;
}

void Empty()
{
	if (top_cnt == -1)
	{
		printf("\t\t0, False\n");
		Sleep(500);
		return;
	}
	else
	{
		printf("\t\t1, True\n");
		Sleep(500);
		return;
	}
}
