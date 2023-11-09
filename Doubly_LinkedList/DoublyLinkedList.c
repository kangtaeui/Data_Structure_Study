#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#pragma warning (disable :4996) 

typedef struct D_Node
{
	int value;
	struct D_Node* next;
	struct D_Node* prev;
}D_Node;

D_Node* head = NULL;	//시작
D_Node* tail = NULL;	//끝
//삽입
void front_insert();
void behind_insert();
void front_Nth_insert();
//삭제
void delete_front_node();
void delete_tail_node();
void delete_all_node();
void delete_Nth_node();
void delete_value_node();
//순회, 검색, 역순
void travel_Node();
void search_Node();
int node_Count();
void reverse_node();

int main()
{
	int choice;
	while (1)
	{
		printf("\n\n\t *** 이중 연결 리스트(Doubly Linked List) ***\n\n");
		printf(" 1. 노드 삽입(맨 앞)\n");
		printf(" 2. 노드 삽입(맨 뒤)\n");
		printf(" 3. 노드 삽입(오름차순 정렬//구현x)\n");
		printf(" 4. 노드 삽입(앞에서부터 N번째)\n");
		printf("------------------------------\n");
		printf(" 5. 노드 삭제(맨 앞)\n");
		printf(" 6. 노드 삭제(맨 뒤)\n");
		printf(" 7. 노드 삭제(전체 노드)\n");
		printf(" 8. 노드 삭제(앞에서부터 N번째)\n");
		printf(" 9. 노드 삭제(특정 값)\n");
		printf("------------------------------\n");
		printf("10. 노드 순회 | 이중 연결 리스트 출력\n");
		printf("11. 노드 검색\n");
		printf("12. 노드 개수 구하기\n");
		printf("13. 노드 역순 연결\n");
		printf(" 0. 프로그램 종료\n");
		printf("------------------------------\n");
		printf("\n메뉴 선택 : [  ]\b\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');
		system("cls");
		if (choice == 1)
		{
			front_insert();
			system("cls");
			continue;
		}
		else if (choice == 2)
		{
			behind_insert();
			system("cls");
			continue;
		}
		else if (choice == 3)
		{
			printf("구현 안했습니다..ㅎㅎㅎㅎ\n");
			Sleep(500);
			continue;
		}
		else if (choice == 4)
		{
			front_Nth_insert();
			continue;
		}
		else if (choice == 5)
		{
			delete_front_node();
			system("cls");
			continue;
		}
		else if (choice == 6)
		{
			delete_tail_node();
			system("cls");
			continue;
		}
		else if (choice == 7)
		{
			delete_all_node();
			system("cls");
			continue;
		}
		else if (choice == 8)
		{
			delete_Nth_node();
			system("cls");
			continue;
		}
		else if (choice == 9)
		{
			delete_value_node();
			system("cls");
			continue;
		}
		else if (choice == 10)
		{
			travel_Node();
			continue;
		}
		else if (choice == 11)
		{
			search_Node();
			continue;
		}
		else if (choice == 12)
		{
			node_Count();
			system("cls");
			continue;
		}
		else if (choice == 13)
		{
			reverse_node();
			system("cls");
			continue;
		}
		else if (choice == 0)
		{
			printf("종료합니다.\n");
			system("pause");
			return;
		}
		else
		{
			printf("잘못입력하셨습니다. 다시 입력해주세요\n");
			continue;
		}
	}

	return 0;
}
//---------------------------------------------------	삽 입	------------------------------------------------------------------//
//노드 삽입 ( 맨 앞 )
void front_insert()
{
	system("cls");
	D_Node* newNode;
	newNode = (D_Node*)malloc(sizeof(D_Node));
	printf("노드 삽입 (맨 앞)을 실행하겠습니다.\n");
	printf("삽입하고 싶은 숫자를 입력해주세요 :");
	scanf("%d", &newNode->value);
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
		printf("생성된 노드가 없었습니다. 노드를 생성했습니다\n");
		Sleep(500);
		return;
	}
	newNode->next = head;	//newNode ->next ==null
	head->prev = newNode;
	head = newNode;
	printf("노드삽입을 완료했습니다.\n");
	Sleep(500);
}
void front_Nth_insert()
{
	int Nth;
	D_Node* newNode, *curNode;
	newNode = (D_Node*)malloc(sizeof(D_Node));
	printf("몇번째에 넣고싶은지 입력해주세요 :");
	scanf("%d", &Nth);
	while (getchar() != '\n');
	int Count = node_Count();
	printf("\n다음으로는 넣고싶은 value값을 입력해주세요 ;");
	scanf("%d", &newNode->value);
	while (getchar() != '\n');
	newNode->next = NULL;
	newNode->prev = NULL;
	if (head == NULL || Count+1<Nth)		//생성되지않았거나 입력된 Nth가 count보다 클경우
	{
		printf("노드를 삽입할 수 있는 환경이 아닙니다.\n");
		Sleep(500);
		return;
	}
	//처음
	else if (Nth == 1)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		printf("첫번째 노드에 삽입을 성공했습니다.");
		Sleep(500);
		system("cls");
		return;
	}
	//끝
	else if (Nth == Count+1)
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		printf("마지막 노드에 삽입을 성공했습니다.\n");
		Sleep(500);
		system("cls");
		return;
	}
	//중간
	else if (Nth>1 || Nth < Count+1)
	{
		curNode = head;
		for (int i = 1; i <= Nth-1; i++) //추가할 노드 앞에서 stop
		{
			curNode = curNode->next;//curNode이동
		}

		//newNode 값 변경
		newNode->prev = curNode->prev; 
		newNode->next = curNode;
		

		//newNode 연결
		newNode->prev->next = newNode;
		newNode->next->prev = newNode;

		printf("삽입 완료했습니다.\n");
		Sleep(500);
		system("cls");
	}
}
	
	
//노드 삽입 ( 맨 뒤 )
void behind_insert()
{
	D_Node* newNode;
	newNode = (D_Node*)malloc(sizeof(D_Node));
	printf("노드 삽입 (맨 뒤)를 실행하겠습니다.\n");
	printf("삽입하고 싶은 숫자를 입력해주세요 :");
	scanf("%d", &newNode->value);
	while (getchar() != '\n');
	newNode->next = NULL;
	newNode->prev = NULL;
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
		printf("생성된 노드가 없어서 새로 생성하였습니다.\n");
		Sleep(500);
		return;
	}
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	printf("노드 삽입 (후방)을 완료했습니다.\n");
	Sleep(500);
}
//=============================================	삭제 =============================================
//맨 앞 삭제
void delete_front_node()
{
	D_Node* delNode;
	if (head == NULL)
	{
		printf("삭제할 노드 값이 없습니다.\n");
		Sleep(500);
		return;
	}
	delNode = head;
	head = head->next;
	free(delNode);

	//삭제하고 난 다음
	if (head == NULL)
	{
		tail = NULL;
		printf("생성된 노드는 하나였습니다.\n");
		printf("노드 삭제 (맨 앞)을 완료했습니다.\n");
		Sleep(500);
		return;
	}
	else if (head != NULL)
	{
		head->prev = NULL;
		printf("노드 삭제 (맨 앞)을 완료했습니다.\n");
		Sleep(500);
		return;
	}
}

//맨 뒤
void delete_tail_node()
{
	D_Node* deleteNode;
	if (head == NULL)
	{
		printf("\n\n\t\t연결리스트가 구성 되지 않아 삭제할 노드가 없습니다.\n");
		Sleep(500);
		return;
	}

	deleteNode = tail; //마지막 노드를 삭제할 노드로 설정
	tail = tail->prev; //마지막 노드를 이전 노드로 변경
	free(deleteNode); //마지막 노드 제거

	if (tail != NULL)
	{
		tail->next = NULL;
	}

	if (tail == NULL)
	{
		head = NULL;
	}

	printf("노드 삭제 (맨 뒤)를 실행했습니다.\n");
	Sleep(500);
}

//전체노드
void delete_all_node()
{
	printf("노드 전체 삭제를 진행하겠습니다...\n");
	Sleep(500);
	D_Node* curNode, *deleteNode;
	if (head == NULL)
	{
		printf("삭제할 노드가 없습니다.\n");
		Sleep(500);
		return;
	}
	curNode = head;
	while (curNode->next != NULL)
	{
		deleteNode = curNode;
		curNode = curNode->next;
		free(deleteNode);
	}
	head = NULL;
	tail = NULL;
	printf("모두 삭제가 완료되었습니다.\n");
	Sleep(500);
}

//특정값
void delete_value_node()
{
	int what;
	D_Node* deleteNode;
	deleteNode = head;
	printf("지우고싶은 value값을 입력해주세요 :");
	scanf("%d", &what);
	while (getchar() != '\n');
	if (head == NULL)
	{
		printf("생성된 노드가 없습니다.\n");
		Sleep(500);
		return;
	}
	while (deleteNode->next != NULL)
	{
		if (deleteNode->value == what)
		{
			if (deleteNode == head)
			{
				delete_front_node();
				return;
			}
			else
			{
				deleteNode->prev->next = deleteNode->next;
				deleteNode->next->prev = deleteNode->prev;
				free(deleteNode);
				printf("노드 값 : %d를 삭제했습니다.", what);
				Sleep(500);
				return;
			}
		}
		deleteNode = deleteNode->next;
	}
	//지우려는 값이 맨 끝 tail인 경우
	if (deleteNode == tail && deleteNode->value == what)
	{
		delete_tail_node();
		return;
	}
}

//N번째 노드 삭제
void delete_Nth_node()
{
	D_Node* deleteNode;
	int Nth;
	int count = node_Count();
	printf("N번째 노드 삭제를 진행하겠습니다.\n");
	printf("N의 값을 입력해주세요 :");
	scanf("%d", &Nth);
	while (getchar() != '\n');
	deleteNode = head;
	//삭제 불가
	if (Nth<1 || Nth>count)
	{
		printf("노드를 삭제할 수 없는 환경입니다.\n");
		Sleep(500);
		return;
	}
	if (head == NULL)
	{
		printf("생성된 노드가 없어서 삭제할 수 없습니다.\n");
		Sleep(500);
		return;
	}
	//첫번째
	if (count == 1)
	{
		head = head->next;
		free(deleteNode);
		head->prev = NULL;
		printf("입력하신 N이 1이라 첫번째 노드를 삭제했습니다.");
		Sleep(500);
		return;
	}
	//tail노드
	if (Nth == count)
	{
		delete_tail_node();
		return;
	}
	//일반
	for (int i = 0; i < Nth - 1; i++)
	{
		deleteNode = deleteNode->next;	//끝 전까지 이동
	}
	deleteNode->prev->next = deleteNode->next;		//삭제하기위해 앞뒤 연견 prev를 뒤로 하게끔
	deleteNode->next->prev = deleteNode->prev;		// 넥스트와 prev
	free(deleteNode);
	printf(" %d번째 노드를 삭제했습니다.\n",Nth);
}




//===================================순회, 검색, 역순 등등 =====================================
void travel_Node()
{
	D_Node* curNode;
	printf("노드 순회를 시작하겠습니다.\n");
	printf("잠시만 기다려주세요...\n");
	Sleep(1000);
	if (head == NULL)
	{
		printf("노드가 생성되지 않았습니다.\n");
		Sleep(500);
		system("cls");
		return;
	}
	//아무리봐도 curNode라는 변수에 헤드를 넣어서 next 값이 Null까지 가는 방법이 안돼서 
	// 생각해보니 다음 노드가 존재하는 Boolean식으로 와일문에 넣어주니 된다.

	curNode = head; 
	while (curNode->next)
	{
		printf("%d => ", curNode->value);
		curNode = curNode->next;	//10의 길이에서 8까지 이동하는데 8의 next값을 8에다 넣으니 9까지 가는거와 다름없다.
	}
	printf("%d", curNode->value);
	printf("\n");	//맨 마지막항 출력
	system("pause");
	system("cls");
}

void search_Node()
{
	int what;
	D_Node* curNode;
	printf("노드 검색을 실행하겠습니다.\n");
	printf("찾으실 노드를 입력해주세요 :");
	scanf("%d",&what);
	while (getchar() != '\n');

	if (head == NULL)
	{
		printf("노드가 생성조차 되지 않았습니다.\n");
		Sleep(500);
		system("cls");
		return;
	}
	curNode = head;
	while (curNode->next)
	{
		if (curNode->value == what)
		{
			printf("찾으시는 노드는 존재합니다.\n");
			Sleep(500);
			system("cls");
			return;
		}
		curNode = curNode->next;
	}
	if (curNode->value == what)
	{
		printf("찾으시는 노드는 존재합니다.\n");
		Sleep(500);
		system("cls");
		return;
	}
	else
	{
		printf("찾으시는 노드는 존재하지 않습니다.\n");
		Sleep(500);
		system("cls");
		return;
	}
}

int node_Count()
{
	int cnt = 0;
	D_Node* curNode;
	if (head == NULL)
	{
		printf("생성된 노드는 0개 입니다.\n");
		Sleep(500);
		return cnt;
	}
	curNode = head;
	while (curNode->next != NULL)
	{
		curNode = curNode->next;
		cnt++;
	}
	cnt++;
	printf("생성된 노드는 총 %d개입니다.\n", cnt);
	Sleep(500);
	return cnt;
}

//역순
void reverse_node()
{
	D_Node* curNode, * tempNode;
	if (head == NULL || head->next == NULL) //노드 1개 이하일 때
	{
		return;
	}

	curNode = head;
	tail = head; //처음 == 마지막

	while (curNode != NULL) //계속 이동하려고
	{
		//이전주소와 다음주소를 swap
		tempNode = curNode->prev;
		curNode->prev = curNode->next;
		curNode->next = tempNode;

		if (curNode->prev == NULL)
		{
			head = curNode;
			printf("역순 연결을 완료했습니다..\n");
			Sleep(500);
			return;
		}

		curNode = curNode->prev; //prev로 이동
	}
}
