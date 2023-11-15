#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int arr[100001];
int compare[100001];
int sorted[100001];

void mergeSort(int* arr, int n, int m);
void merge(int* arr, int n, int middle, int m);
int upper_cnt=0;
int lower_cnt=0;


int main()
{
	int m;
	int n;
	int index = 0;
	scanf("%d", &n);				//배열에 추가			
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	scanf("%d", &m);			//찾을 숫자들의 배열 입력하기
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &compare[i]);
	}

	mergeSort(arr, 0, n - 1);
	
	for (int i = 0; i < m; i++)
	{
		int upper_cnt = upper_body(arr, 0, n - 1, compare[i]);			//상위 검사
		int lower_cnt = lower_body(arr, 0, n - 1, compare[i]);			//하위 검사
		
		printf("%d ", upper_cnt-lower_cnt);
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


int upper_body(int* arr, int left, int right,int find) //상위
{
	int mid = (left + right) / 2;
	
	if (left > right)				//left값이 right보다 크다면 종료
	{
		return left;
	}

	if (arr[mid] == find)		//하위에서 찾는값과 arr[mid]가 같을 때도 재귀호출 이뤄지고 left가 right보다 크면 left 리턴해주고 종료
	{
		return upper_body(arr, mid + 1, right, find);

	}
	
	if (arr[mid] < find)
	{
		return upper_body(arr, mid + 1, right, find);
	}
	else
	{
		return upper_body(arr, left, mid - 1, find);
	}

}

int lower_body(int *arr, int left, int right,int find)		//하위
{
	int mid = (left + right) / 2; 
	
	if (left > right)		//left값이 right보다 크다면 종료
	{
		return left;
	}

	if (arr[mid] == find)		//하위에서 찾는값과 arr[mid]가 같을 때도 재귀호출 이뤄지고 left가 right보다 크면 left 리턴해주고 종료
	{
		return lower_body(arr, left, mid - 1,find);
	}
	
	if (arr[mid] < find)
	{
		return lower_body(arr, mid + 1, right, find);
	}
	else
	{
		return lower_body(arr, left, mid - 1, find);
	}

}
