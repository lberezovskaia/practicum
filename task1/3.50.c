#include <stdio.h>

int main(void){
    char ch;
    char s[100];
    int i = 0;
    int flag = 0;
    int count = 0;
    printf("enter your sequence: ");
    while ((ch = getchar()) != '$'){
        if (ch >= '0' && ch <= '9'){
            if (flag){
                count++;
                if (count > 2){
                    continue;
                }
            }
            else{
                count = 1;
            }
        }
        else{
            flag = 0;
            count = 0;
        }
        if (ch == '.')
        {
            flag = 1;
        }
        *(s + i) = ch;
        i++;
    }
    *(s + i) = '\0';
    printf("processed sequence: %s\n", s);
    return 0;
}
