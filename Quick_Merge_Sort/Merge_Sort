#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)


int arr[10000];
int sorted[10000];	//반드시 전역 변수여야 한다.

void merge(int *arr, int n, int middle, int m)		//시작점, 중간점, 끝점
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

//반 나누기
void mergeSort(int *arr, int n, int m)
{
	//크기가 1보다 큰 경우에만
	if (n < m)
	{
		int middle = (n + m) / 2;
		mergeSort(arr, n, middle);		//왼쪽배열
		mergeSort(arr, middle+1, m);		//오른쪽 배열
		merge(arr, n, middle, m);		//합치기
	}
} 

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	mergeSort(arr, 0, num - 1);

	for (int i = 0; i < num; i++)
	{
		printf("%d\n", arr[i]);
	}
}
