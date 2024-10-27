#include <stdio.h>
#include <string.h>

int frequency(char *s, int n, char x){
    char ch;
    char temp;
    for (int i = 0; i < strlen(s) - 1; i++) { // сортировка строки
        for (int j = 0; j < strlen(s) - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    int count = 0;
    int i = 1;
    while ((ch = *(s + i)) != '\0'){ // нахождение символа с наименьшим вхождением
        for (int j = 1; j < strlen(s); j++){
            if (*(s + j) == ch){
                count++;
            }
        }
        if (n > count){
            n = count;
            x = ch;
        }
        count = 0;
        i++;
    }
    printf("the rarest symbol: %c\n", x);
    printf("number of occurrences: %d", n);
}

int main(void){
    char str[100];
    int n = 100;
    char x;
    printf("enter your string: ");
    fgets(str, 100, stdin);
    frequency(str, n, x);
    return 0;
}
