#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)


//3.피보나치
long long fibo(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1 || n == 2)
	{
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);	//n-1일때랑 n-2일때 호출해서 더해준다.
}

int main()
{
	int n;
	long long result;
	printf("피보나치 몇번째 항을 구할건지 입력하세요 :");
	scanf("%d", &n);
	result = fibo(n);
	printf("%lld", result);
	return 0;
}
