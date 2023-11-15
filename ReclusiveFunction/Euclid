#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

2.유클리드
int gcd(int x, int y)
{
	if (y == 0)	//0일 때 재귀 호출을 못하게 
	{
		return x;
	}
	return gcd(y, x % y);		//사각형이라 생각했을 때 x/y해서 나머지 값을 남기고, 그값을 y자리에 넣고 x자리에는 기존의 y값을 넣어서 리턴해준다.
}

int lcm(int n1, int n2)		//최소공배수 함수 구현
{
	int great;
	int least;
	great = gcd(n1, n2);
	least = (n1 * n2) / great;
  return least;
}

int main()
{
	int n1,n2;
	int result1;
	int result2;
	printf("수를 입력하세요 :");
	scanf("%d %d", &n1,&n2);
	result1 = gcd(n1, n2);
	result2 = lcm(n1, n2);
	printf("%d\n", result1);
	printf("%d\n", result2);
	return 0;
}
