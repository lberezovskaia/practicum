#include <stdio.h>

int main(void)
{
char str;
char a[100];
int indig = 0;
int i = 0;
int count = 0;
while ((str = getchar()) != '$')
{
    if ((str >= '0') && (str <= '9'))
    {
        if (indig == 0)
        {
            a[i] = str;
            i++;
        };
        if (indig == 1)
        {
            if (count > 1)
            {
                continue;
            }
            else
            {
                a[i] = str;
                i++;
                count++;
            };
        };
    };
    if (str = '.')
    {
        a[i] = str;
        i++;
        indig = 1;
    }
    else 
    {
        a[i] = str;
        i++;
        count = 0; 
    }
}
a[i] = '\0';
printf("%s\n", a);
return 0;
}
