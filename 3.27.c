#include <stdio.h>
#include <math.h>

int main(void)
{
    long int n = 0;
    scanf("%ld", &n);
    long int ans;
    int a[100];
    int i = 0;
    while (n != 0)
    {
        if (((n % 10) != 0) && ((n % 10) != 5))
        {
            i++;
            a[i] = n % 10;
        };
         n = n / 10;
    };
    for (i; i > 0; i--)
    {
        ans = ans + (a[i] * pow(10, i-1));;
    };
    printf("%ld\n", ans);
    return 0;
}
