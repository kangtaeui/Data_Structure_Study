#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable : 4996)

typedef struct node
{
	int value;
	struct node* next;
}node;

node* head = NULL;

void insert_front();
void insert_back();
void delete_node();
void print_all();
void sort_node();
void insert_front_Nth();
void delete_front();
void delete_back();
void search_node();
int count_node();
void delete_Nth();
void delete_what();



int main()
{
	int select;
	printf("노드 출력을 진행하겠습니다.\n");
	while (1)
	{

		printf("\n\n\t *** 단일 연결 리스트(Singly Linked List) ***\n\n");
		printf(" 1. 노드 삽입(맨 앞)\n");
		printf(" 2. 노드 삽입(맨 뒤)\n");
		printf(" 3. 노드 삽입(오름차순 정렬)\n");
		printf(" 4. 노드 삽입(앞에서부터 N번째)\n");
		printf("------------------------------\n");
		printf(" 5. 노드 삭제(맨 앞)\n");
		printf(" 6. 노드 삭제(전체 노드)\n");
		printf(" 7. 노드 삭제(앞에서부터 N번째)\n");
		printf(" 8. 노드 삭제(특정 값)\n");
		printf(" 9. 노드 삭제(맨 뒤)\n");
		printf("------------------------------\n");
		printf("10. 노드 순회 | 단일 연결 리스트 출력\n");
		printf("11. 노드 검색\n");
		printf("12. 노드 개수 구하기\n");
		printf(" 0. 프로그램 종료\n");
		printf("------------------------------\n");
		printf("\n메뉴 선택 : [  ]\b\b\b");
		scanf("%d", &select);
		while (getchar() != '\n');
		if (select == 1)
		{
			printf("맨 앞 삽입을 실행하겠습니다.\n");
			insert_front();
			system("pause");
			system("cls");
			continue;
		}
		else if (select == 2)
		{
			printf("맨 뒤 삽입을 실행하겠습니다.\n");
			insert_back();
			system("pause");
			system("cls");
			continue;
		}
		else if (select == 3)
		{
			printf("정렬 삽입을 실행하겠습니다.\n");
			sort_node();
			system("pause");
			system("cls");
			continue;
		}
		else if (select == 4)
		{
			printf("N번째 삽입을 실행하겠습니다.\n");
			insert_front_Nth();
			system("pause");
			system("cls");
			continue;
		}
		else if (select == 5)
		{
			printf("노드의 맨 앞을 삭제를 실행하겠습니다.\n");
			delete_front();
			system("pause");
			system("cls");
			continue;
		}
		else if (select == 6)
		{
			printf("전체 삭제를 실행하겠습니다.\n");
			delete_node();
			system("pause");
			system("cls");
			continue;
		}
		else if (select == 7)
		{
			printf("N번째 노드 삭제를 실행하겠습니다.\n");
			delete_Nth();
			system("pause");
			system("cls");
			continue;

		}
		else if (select == 8)
		{
			printf("노드 특정 값 삭제를 실행하겠습니다.\n");
			delete_what();
			system("pause");
			system("cls");
			continue;
		}
		else if (select == 9)
		{
			printf("노드의 맨 뒤를 삭제를 실행하겠습니다.\n");
			delete_back();
			system("pause");
			system("cls");
			continue;
		}
		else if (select == 10)
		{
			printf("순회를 실행하겠습니다.\n");
			print_all();
			system("pause");
			system("cls");
			continue;
		}
		else if (select == 11)
		{
			printf("검색을 실행하겠습니다.\n");
			search_node();
			system("pause");
			system("cls");
			continue;
		}
		else if (select == 12)
		{
			printf("노드의 개수를 탐색하겠습니다.\n");
			count_node();
			system("pause");
			system("cls");
			continue;
		}
		else if (select == 0)
		{
			printf("종료하겠습니다...\n");
			Sleep(1000);
			return;
		}
		else
		{
			printf("잘못 입력하셨습니다.\n");
			system("pause");
			system("cls");
			continue;
		}
	}
}

//맨 앞에 값 넣어주기.
void insert_front()
{
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	printf("삽입할 값을 입력해주세요 :");
	scanf("%d", &newNode->value);
	while (getchar() != '\n');
	newNode->next = NULL;
	if (head == NULL)
	{
		head = newNode;
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("노드가 생성되지 않아 처음으로 생성하였습니다.\n\n");
		return;
	}
	newNode->next = head;
	head = newNode;
	printf("로딩중입니다...\n");
	Sleep(1000);
	printf("노드를 생성하였습니다.\n");

}
//순회하기
void print_all()
{
	node* curNode;
	if (head == NULL)
	{
		printf("로딩중입니다...\n");
		Sleep(1000);

		printf("노드가 아무것도 생성되지 않아 순회할 값이 없습니다.\n");
		system("pause");
		system("cls");
		return;
	}
	curNode = head;
	printf("로딩중입니다.\n");
	Sleep(1000);
	while (curNode->next != NULL) {
		printf("%d =>", curNode->value);
		curNode = curNode->next;
	}
	printf("%d\n", curNode->value); //마지막 노드 출력
	printf("모든 노드를 순회하였습니다.\n");
}
//맨 뒤에 삽입
void insert_back()
{
	node* newNode, * curNode;
	newNode = (node*)malloc(sizeof(node));
	printf("삽입할 값을 입력해주세요 :");
	scanf("%d", &newNode->value);
	while (getchar() != '\n');
	newNode->next = NULL;	//첫 노드 생성
	if (head == NULL)
	{
		head = newNode;
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("어떠한 값도 삽입되지 않은 관계로 첫 노드가 생성되었습니다.\n");
		return;
	}
	curNode = head;
	while (curNode->next != NULL)
	{
		curNode = curNode->next;
	}
	curNode->next = newNode;
	printf("로딩중입니다...\n");
	Sleep(1000);
	printf("노드 후방삽입이 완료되었습니다.\n");
}

//전체 노드 삭제
void delete_node()
{
	node* removeNode;
	if (head == NULL)
	{
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("삭제할 값이 없습니다.\n");
		system("pause");
		system("cls");
		return;
	}

	while (head != NULL)	//생성된 노드가 있다면 계속해서 제거.
	{
		removeNode = head;
		head = head->next;
		free(removeNode);
	}
	printf("로딩중입니다...\n");
	Sleep(1000);
	printf("모든 노드값이 삭제되었습니다.\n");
}




//정렬삽입
void sort_node()
{
	node* prevNode, * curNode, * newNode;
	newNode = (node*)malloc(sizeof(node));
	printf("정렬삽입 하고싶은 노드값을 입력해주세요 :");
	scanf("%d", &newNode->value);
	while (getchar() != '\n');
	newNode->next = NULL;
	if (head == NULL)
	{
		head = newNode;
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("생성된 노드 값이 없어서 새로 만들었습니다. 당연히 정렬은 아닙니다.\n");
		Sleep(1000);
		return;
	}
	if (head->value > newNode->value)
	{
		newNode->next = head;
		head = newNode;
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("삽입하려는 노드의 값이 가장 작아서 맨 앞에 삽입했습니다.\n");
		Sleep(1000);
		return;
	}
	prevNode = curNode = head;
	while (curNode->next != NULL)
	{
		curNode = curNode->next;
		if (curNode->value > newNode->value)
		{
			newNode->next = curNode;
			prevNode->next = newNode;
			printf("로딩중입니다...\n");
			Sleep(1000);
			printf("노드 삽입을 마쳤습니다.\n");
			return 1;
		}
		prevNode = prevNode->next;
	}
	//마지막 값이 제일 클 때
	if (newNode->value > curNode->value)
	{
		curNode->next = newNode;
		printf("생성하신 노드가 가장 큰값이라 마지막에 넣었습니다.\n");
		Sleep(1000);
		return;
	}
}

//N번쨰 삽입하기.
void insert_front_Nth()
{
	int n;
	node* newNode, * curNode;
	newNode = (node*)malloc(sizeof(node));
	printf("N번째에 삽입하고 싶은지 입력하세요 : ");
	scanf("%d", &n);
	while (getchar() != '\n');
	int available_count = count_node();	//갯수
	if (head == NULL)
	{
		printf("노드가 생성되지않아서 N번째에 삽입할 수 없습니다.\n");
		Sleep(1000);
		return;
	}
	while (1)
	{
		if (n<1 || n > available_count + 1)//맨뒤를 넘어서니까 +1
		{
			printf("로딩중입니다...\n");
			Sleep(1000);
			printf("아쉽지만 삽입할 수 있는 범위가 아닙니다.\n");
			printf("다시 골라주세요\n");
			Sleep(1000);
			return;
		}
		else
		{
			printf("로딩중입니다...\n");
			Sleep(1000);
			printf("가능합니다!\n");
			break;
		}
	}
	printf("이번에는 삽입하고 싶은 숫자를 입력해주세요\n");
	scanf("%d", &newNode->value);
	newNode->next = NULL;
	if (n == 1)
	{
		newNode->next = head;
		head = newNode;
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("첫번째 노드삽입에 성공했습니다. ");
		return;
	}
	curNode = head;
	for (int i = 0; i < n - 2; i++)
	{
		curNode = curNode->next;
	}
	newNode->next = curNode->next;
	curNode->next = newNode;
	printf("로딩중입니다...\n");
	Sleep(1000);
	printf("삽입에 성공하였습니다.\n");
}

//검색하기
void search_node()
{
	int findwhat;
	node* curNode;
	curNode = head;
	printf("찾으실 노드의 value값을 입력해주세요 : ");
	scanf("%d", &findwhat);
	while (getchar() != '\n');
	if (head == NULL)
	{
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("\n\n노드가 생성조차 되지 않았습니다.\n");
		system("pause");
		system("cls");
		return;
	}
	while (curNode->next != NULL)
	{
		if (curNode->value == findwhat)
		{
			printf("로딩중입니다...\n");
			Sleep(1000);
			printf("찾으시려는 노드는 존재합니다...!\n");
			return;
		}
		curNode = curNode->next;
	}
	if (curNode->value == findwhat)
	{
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("찾으시려는 노드는 존재합니다...!\n");
		return;
	}
	else if (curNode->value != findwhat)
	{
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("찾으시는 노드는 존재하지 않습니다.\n");
		Sleep(1000);
		return;
	}
}
//노드 개수 세기
int count_node()
{
	int count = 0;
	node* curNode;
	curNode = head;
	if (head == NULL)
	{
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("노드가 생성되지 않았습니다.\n");
		printf("개수는 0개 입니다.\n");
		Sleep(500);
		return;
	}
	while (curNode->next != NULL)
	{
		curNode = curNode->next;
		count++;
	}
	count++;
	printf("로딩중입니다...\n");
	Sleep(1000);
	printf("총 개수는 %d개 입니다.\n", count);
	return count;
}
// 맨 앞 삭제
void delete_front()
{
	node* removeNode;
	removeNode = head;
	if (head == NULL)
	{
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("어떠한 값도 생성되지 않아서 삭제할 수 없습니다.\n");
		Sleep(1000);
		return;
	}
	head = head->next;
	free(removeNode);
	printf("로딩중입니다...\n");
	Sleep(1000);
	printf("맨 앞의 노드를 삭제했습니다.\n");
	Sleep(1000);
}

//맨 뒤 삭제.
void delete_back()
{
	node* removeNode;
	removeNode = head;
	if (head == NULL)
	{
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("어떠한 값도 생성되지 않아서 삭제할 수 없습니다.\n");
		Sleep(1000);
		return;
	}

	//1개 있을 때랑 여러개 있을 때 나눠서 코딩.
	//이전 노드값 있어야한다. 전 노드의 넥스트값을 널로 바꿔줘야 한다.
	if (head->next == NULL)	//1개 있을 때
	{
		free(removeNode);
		head = NULL;
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("노드가 딱 1개였고, 1개를 삭제했습니다.\n");
		return;
	}

	while (removeNode->next->next != NULL)	//removenode=head된 상태고 널까지 갈때 
	{
		removeNode = removeNode->next;
	}
	free(removeNode->next);
	removeNode->next = NULL; //삭제하고 널값 대입
	printf("로딩중입니다...\n");
	Sleep(1000);
	printf("맨 뒤의 노드를 삭제했습니다.\n");
	Sleep(1000);
}

//앞에서 n번째 삭제
void delete_Nth()
{
	int n;
	node* removeNode, * prevNode;
	prevNode = removeNode = head;
	int available_count = count_node();
	if (head == NULL)
	{
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("삭제할 노드가 없습니다!\n");
		Sleep(500);
		return;
	}
	printf("삭제하고 싶은 N번째를 입력해주세요 : ");
	scanf("%d", &n);
	while (getchar() != '\n');
	if (n<1 || n> available_count)
	{
		printf("죄송합니다 불가능합니다. 다시 골라주세요\n");
		Sleep(500);
		return;
	}
	if (n == 1)
	{
		printf("로딩중입니다...\n");
		Sleep(1000);
		head = head->next;
		free(removeNode);
		printf("첫번째 삭제를 성공했습니다.\n");
		return;
	}
	for (int i = 1; i < n - 1; i++)	//n항 한칸 전까지 이동		입력받은 n -1까지 prevNode를, n까지 removeNode를 이동시키려고.
	{
		prevNode = prevNode->next;
	}
	removeNode = prevNode->next; //서로 연결

	prevNode->next = removeNode->next;	//다시 재연결
	free(removeNode);
	printf("로딩중입니다...\n");
	Sleep(1000);
	printf("%d번째 삭제를 완료했습니다.\n", n);
	Sleep(1000);
	return 1;
}

void delete_what()
{
	node* removeNode, * prevNode;
	int data;
	removeNode = prevNode = head;
	printf("삭제하고 싶은 값을 입력해주세요 : ");
	scanf("%d", &data);
	while (getchar() != '\n');

	if (head == NULL)
	{
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("노드가 생성되지 않아서 삭제할 값이 없습니다.\n");
		Sleep(1000);
		return;
	}
	if (head->value == data)
	{
		head = head->next;
		free(removeNode);
		printf("로딩중입니다...\n");
		Sleep(1000);
		printf("입력하신 값이 첫 노드여서 첫 노드를 제거하였습니다.\n");
		return;
	}
	while (removeNode->next != NULL)
	{
		removeNode = removeNode->next;
		if (removeNode->value == data)
		{
			prevNode->next = removeNode->next;
			free(removeNode);
			printf("로딩중입니다...\n");
			Sleep(1000);
			printf("삭제에 성공하였습니다.\n");
			return;
		}
		prevNode = prevNode->next;
	}
	printf("로딩중입니다...\n");
	Sleep(1000);
	printf("삭제할 값이 존재하지 않습니다.\n");
	return;
}
