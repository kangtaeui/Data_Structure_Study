#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

int data[100000];

void quick(int *data, int start, int end);

int main()
{
	int number;
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{
		scanf("%d", &data[i]);
	}
	quick(data, 0, number - 1);
	for (int i = 0; i < number; i++)
	{
		printf("%d", data[i]);
	}
}

void quick(int *data, int start, int end)
{
	if (start >= end)	
	{
		return;
	}
	int key = start;	
	int i = start + 1;	
	int j = end,temp;	

	while (i <= j)	
	{
		while (i<=end && data[i] <= data[key])	
		{
			i++;
		}
		while (data[j] >= data[key] && j>start)
		{
			j--;
		}
		if (i > j)	
		{
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quick(data, start, j - 1);
	quick(data, j+1, end);
}
