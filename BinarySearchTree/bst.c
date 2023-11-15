#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#pragma warning (disable : 4996)


typedef struct {
	int value;
	struct tree* left;
	struct tree* right;
}tree;

enum menu {
	INSERT=1, REMOVE, SEARCH, MAX_VALUE, MIN_VALUE, PREORDER, INORDER, POSTORDER, TREE_SUM, TREE_NODE_EA, TREE_HEIGHT, EXIT=0
};

tree* insert_value(tree* t, int num);
tree* Large_value(tree* t);
tree* Small_value(tree* t);
void traversal_preorder(tree* t);
void traversal_inorder(tree* t);
void traversal_postorder(tree* t);
int tree_height(tree* t);
tree* remove_what(tree* t, int what);
int tree_sum(tree* t);
int tree_node_ea(tree* t);
tree* tree_search(tree* t, int what);
int cnt = 0;
int cnt_ea = 0;
int cnt_sum = 0;
int cnt_max = 0;
int cnt_min = 0;
int cnt_height = 0;

int main()
{
	int choice;
	int what;
	tree* treeNode = NULL;
	int cnt_height = 0;
	while (1)
	{
		system("cls");
		printf("\n\n\t\t*** binary search tree ***\n");
		printf("\t\t1. INSERT    2. DELETE    3. SEARCH    4. MAX_VALUE    5. MIN_VALUE    6. PREDORDER    7. INORDER	8. POSTORDER	9.TREE_SUM	 10.TREE_NODE_EA	  11.TREE_HEIGHT	0.EXIT\n");
		printf("\t\tchoice : [ ]\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');
		printf("\n");
		switch (choice)
		{
		case INSERT:
			printf("삽입하려는 값을 입력하세요 :");
			scanf("%d", &what);
			while (getchar() != '\n');
			treeNode = insert_value(treeNode, what);
			printf("\n삽입 완료\n");
			break;

		case REMOVE:
			printf("삭제하려는 값을 입력하세요 :");
			scanf("%d", &what);
			while (getchar() != '\n');
			treeNode = remove_what(treeNode, what);
			printf("\n삭제를 완료했습니다\n");
			Sleep(500);
			break;

		case SEARCH:
			printf("찾으시려는 값을 입력하세요 :");
			scanf("%d", &what);
			while (getchar() != '\n');
			tree_search(treeNode, what);
			break;

		case MAX_VALUE:
			cnt_max = Large_value(treeNode);
			printf("최댓값 : %d", cnt_max);
			break;

		case MIN_VALUE:
			cnt_min = Small_value(treeNode);
			printf("최솟값 : %d", cnt_min);
			break;

		case PREORDER:
			traversal_preorder(treeNode);
			break;

		case INORDER:
			traversal_inorder(treeNode);
			break;

		case POSTORDER:
			traversal_postorder(treeNode);
			break;

 
		case TREE_SUM:
			cnt_sum = tree_sum(treeNode);
			printf("tree의 합은 %d", cnt_sum);
			Sleep(500);
			break;


		case TREE_NODE_EA:
			cnt_ea = tree_node_ea(treeNode);
			printf("\t\t%d\n", cnt_ea);
			Sleep(500);
			break;

		case TREE_HEIGHT:
			cnt_height = 0;
			cnt_height = tree_height(treeNode);
			printf("%d층\n", cnt_height);
			break;

		case EXIT:
			printf("종료하겠습니다...");
			Sleep(500);
			return;
		}
		printf("\n\n\t\t");
		system("pause");
	}
}

tree* insert_value(tree* t, int num)
{
	if (t == NULL)
	{
		t = (tree*)malloc(sizeof(tree));
		t->value = num;
		t->left = NULL;
		t->right = NULL;
	}
	else if (t->value > num)			//입력한 num이 value보다 작다면 왼쪽
	{
		t->left = insert_value(t->left, num);
	}
	else if (t->value < num)		//입력한 num이 value보다 작다면 오른쪽
	{
		t->right = insert_value(t->right, num);
	}
	return t;	//연결
}

tree* Large_value(tree* t)
{
	if (t != NULL)
	{
		while (t->right)		//t가 null이 아닐 때까지 right로 이동
		{
			t = t->right;
		}
	}
	return t->value;
}

tree* Small_value(tree* t)
{
	if (t != NULL)
	{
		while (t->left != NULL)		//t가 null이 아닐 때까지 left로 이동
		{
			t = t->left;
		}
	}
	return t->value;
}

void traversal_preorder(tree* t)
{
	if (t != NULL)
	{
		printf("%d ", t->value);
		traversal_preorder(t->left);
		traversal_preorder(t->right);
	}
	Sleep(500);
	
}

void traversal_inorder(tree* t)
{
	if (t != NULL)
	{
		traversal_inorder(t->left);
		printf("%d ", t->value);
		traversal_inorder(t->right);
	}
	Sleep(500);
}

void traversal_postorder(tree* t)
{
	if (t != NULL)
	{
		traversal_postorder(t->left);
		traversal_postorder(t->right);
		printf("%d ", t->value);
	}
	Sleep(500);
}

int tree_height(tree* t)
{
	if (t == NULL)
	{
		return cnt;		//cnt를 0이라 해놧고 0층 일때를 나타내기위해서 cnt리턴
	}
	else
	{
		int left_height = tree_height(t->left);
		int right_height = tree_height(t->right);
		return 1 + (left_height > right_height ? left_height : right_height);		//left right 둘다 탐사해서 둘 중 큰쪽을 return
	}
}

int tree_node_ea(tree* t)
{
	if (t != NULL)
	{
		return 1 + tree_node_ea(t->left) + tree_node_ea(t->right);		//재귀호출할때마다 1 더하기
	}
	return 0;
}

tree* tree_search(tree* t, int what)
{
	if (t != NULL)
	{
		if (what == t->value)
		{
			printf("있습니다.\n");
			return t;
		}
		else if (what < t->value)		// value가 찾으려는 값보다 작다면 왼쪽에 있다는 것이니까 left
		{
			tree_search(t->left, what);
		}
		else if (what > t->value)		// value가 찾으려는 값보다 작다면 왼쪽에 있다는 것이니까 right
		{
			tree_search(t->right, what);
		}
	}
	else
	{
		printf("없습니다.\n");
		Sleep(500);
	}
	return t;
}

tree* remove_what(tree* t, int what)
{
	tree* temp;
	if (t != NULL)
	{
		if (t->value == what)
		{
			if (t->left == NULL && t->right == NULL)	//아무것도 없는 겨우
			{
				free(t);
				return NULL;
			}
			else if (t->right == NULL)	//right가 null인 경우
			{
				temp = t->left;
				free(t);
				return temp;	//t의 left값 리턴
			}
			else if (t->left == NULL)		//left가 null인 경우
			{
				temp = t->right;
				free(t);
				return temp;		//t의 right값 리턴
			}
			else			//둘 다 있는 경우
			{
				temp = Large_value(t->left);		//왼쪽중 가장 큰 값을 temp에 저장
				t->value = temp->value;				//value값에 temp값 저장 >>삭제하고 싶은 위치에 넣게된다 그러면 부모가 되는데 왼쪽 값은 무조건 부모보다 작고 오른쪽은 무조건 크다.
				t->left = remove_what(t->left, temp->value);		//왼쪽 서브트리에서 삭제할값을 찾는다.
			}
		}
		else if (t->value > what)
		{
			t->left = remove_what(t->left, what);
		}
		else if (t->value < what)
		{
			t->right = remove_what(t->right, what);
		}
	}
	return t;
}

int tree_sum(tree* t)
{
	if (t != NULL)
	{
		return t->value + tree_sum(t->left) + tree_sum(t->right);	//재귀호출하면서 t->value값들을 호출하면서 모두 더한다.
	}
	return 0;
}
