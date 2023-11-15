#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)


//1.팩토리얼
int factorial(int n)
{
    if (n == 1 || n==0)	//n이 1일때 까지 호출하고, 입력받은 수가 0이라면 1을 호출
    {
        return 1;
    }
    return n * factorial(n - 1); //n이 이 될 때까지 계속 호출해놓고 다시 돌아갈때 호출된 수들을 다 곱하는데 그 형태가 팩토리얼과 같다.
}

int main()
{
    int n;
    int result;
    scanf("%d", &n);
    result = factorial(n);
    printf("%d", result);
}
