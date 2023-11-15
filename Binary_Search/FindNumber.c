#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int arr[100001];
int compare[100001];
int sorted[100001];

void mergeSort(int* arr, int n, int m);
void merge(int* arr, int n, int middle, int m);


int main()
{
	int n;
	int m;
	int index=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &compare[i]);
	}

	mergeSort(arr, 0, n - 1);


	for (int i = 0; i < m; i++)
	{
		index = Binary_Search(arr, 0, n-1, compare[i]);
		if (index == -1)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
	}
	
}

void mergeSort(int* arr, int n, int m)
{
	//크기가 1보다 큰 경우에만
	if (n < m)
	{
		int middle = (n + m) / 2;
		mergeSort(arr, n, middle);		//왼쪽배열
		mergeSort(arr, middle + 1, m);		//오른쪽 배열
		merge(arr, n, middle, m);		//합치기
	}
}

void merge(int* arr, int n, int middle, int m)		//시작점, 중간점, 끝점
{
	int i = n;	//n=0;
	int j = middle + 1;
	int k = n;

	while (i <= middle && j <= m)		//한칸씩 이동
	{
		if (arr[i] <= arr[j])
		{
			sorted[k] = arr[i];		//넣어주고 증가
			i++;
		}
		else
		{
			sorted[k] = arr[j];		//넣어주고 증가
			j++;
		}
		k++;
	}
	//남은 데이터 넣기
	if (i > middle)		//i가 먼저 끝났다면
	{
		for (int t = j; t <= m; t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = arr[t];
			k++;
		}

	}
	//정렬된 것 삽입하기
	for (int t = n; t <= m; t++)
	{
		arr[t] = sorted[t];
	}
}




int Binary_Search(int* arr, int left, int right, int find)
{
	int mid = (left + right) / 2;

	if (left > right)
	{
		return -1;
	}

	if (arr[mid] == find)
	{
		return mid;
	}

	

	if (arr[mid] < find)
	{
		return Binary_Search(arr, mid + 1, right, find);
	}

	else
	{
		return Binary_Search(arr, left, mid - 1, find);
	}
}
