#include <stdio.h>

int main(void)
{
    long n;
    scanf("%ld", &n);
    int a[100];
    int i = 0;
    while (n != 0){
        if ((n % 10) != 0 && (n % 10) != 5){
            *(a + i) = n % 10;
            i++;
        }
        n = n / 10;
    }
    i--;
    for (int j = i; j >= 0; j--){
      printf("%d", *(a + j));
    }
    return 0;
}
