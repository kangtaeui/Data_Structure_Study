#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

#define heap_size 100001
int root = 1;

typedef struct {
    int arr[heap_size];
    int size;
} heap;

void push(heap* h, int value);
int pop(heap* h);
void heapify(heap* h, int parent_idx);

int main()
{
    heap h;
    int size;
    int value;
    h.size = 0;
    scanf("%d", &size);
    while (getchar() != '\n');
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &value);
        if (value == 0)
        {
            printf("%d\n", pop(&h));
        }
        else
        {
            push(&h, value);
        }
    }
}

void push(heap* h, int value)
{
    h->size++;  //size 증가
    int index = h->size;
    while (index > 1 && value < h->arr[index / 2])  //부모와 값을 비교해서 부모가 더 크다면 값을 바꿔준다.
    {
        h->arr[index] = h->arr[index / 2];
        index /= 2;
    }
    h->arr[index] = value;
}

int pop(heap* h)
{
    if (h->size == 0)
    {
        return 0;
    }

    int root_value = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->size--;
    heapify(h, 1);  //parent_idx를 1로 하기 위해 1을 보내준다.
    return root_value;      //min heap이니 제일 상위 값 리턴
}

void heapify(heap* h, int parent_idx)
{
    while (1) {
        int smallest = parent_idx;  //부모값 저장
        int left_child = 2 * parent_idx;    //left 자식
        int right_child = 2 * parent_idx + 1;   //right 자식

        if (left_child <= h->size && h->arr[left_child] < h->arr[smallest]) //left가 사이즈보다 작고 부모보다 작다면
        {
            smallest = left_child;      //smallest_idx에 left값을 넣어준다.
        }

        if (right_child <= h->size && h->arr[right_child] < h->arr[smallest])   //right가 사이즈보다 작고 부모보다 작다면
        {   
            smallest = right_child; //smallest_idx에 right인덱스 넣어준다.
        }

        if (smallest != parent_idx)     //smallest가 넘어온 1 root와 다르다면 swap
        {
            int temp = h->arr[parent_idx];  
            h->arr[parent_idx] = h->arr[smallest];
            h->arr[smallest] = temp;
            parent_idx = smallest;
        }
        else
        {
            break; // 힙 속성이 만족하면 루프 종료
        }
    }
}
