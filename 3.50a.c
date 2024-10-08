#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    char even[100];
    char odd[100];
    int i = 0;
    int k1 = 0;
    int k2 = 0;
    scanf(str);
    gets(str);
    printf("%s\n", str);
    for (i; i < strlen(str); i++)
    {
        if ((i % 2 ) == 0)
        {
            even[k1] = str[i];
            k1++;
        }
        if ((i % 2 ) != 0)
        {
            odd[k2] = str[i];
            k2++;
        }
    }
    even[k1] = '\0';
    odd[k2] = '\0';
    strcat(even, odd);
    printf("%s\n", even);
    return 0;
}
