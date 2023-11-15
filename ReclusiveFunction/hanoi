#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

4.하노이
void hanoi(int num, char start, char temp, char arrive)
{
	if (num == 1)
	{
		printf("%c %c\n", start, arrive);
		return 0;
	}
	hanoi(num - 1, start, arrive, temp);		//temp로 이동
	printf("%c %c\n", start, arrive);
	hanoi(num - 1, temp, start, arrive);		//arrive로 이동
}
int exp(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	return x * exp(x, y - 1);	//y-1이 0이 될 때까지 계속 자기 자신을 호출
}
int main()
{
	int ans, expN;
	scanf("%d", &ans);
	expN = exp(2, ans);
	printf("%d\n", expN - 1);
	hanoi(ans, '1', '2', '3');
	return;
}
