#include <stdio.h>
#include <string.h>

int f(char *s, int n, char x)
{
    int i;
    int j;
    int prev_count = 0;
    int count = 0;
    for (i=0; i < strlen(s); i++)
    {
        if (count > prev_count)
        {
            prev_count = count;
            x = s[i];
        }
        count = 0;
        for (j=0; j < strlen(s); j++)
        {
            if (s[i] == s[j]) 
                count++;
        }
    }
    return 0;
}

int main(void)
{
    char str[100];
    scanf(str);
    gets(str);
    int n = 0;
    char x;
    f(str, n, x);
    return 0;
}
