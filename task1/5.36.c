#include <stdio.h>
#include <string.h>

int main(void){
    char s[100];
    char even[100];
    char odd[100];
    int k1 = 0;
    int k2 = 0;
    printf("enter your sequence: ");
    fgets(s, 100, stdin);
    for (int i = 0; i < strlen(s); i++){
        if ((i % 2 ) == 0){
            *(even + k1) = s[i];
            k1++;
        }
        if ((i % 2 ) != 0){
            *(odd + k2) = s[i];
            k2++;
        }
    }
    *(even + k1) = '\0';
    *(odd + k2) = '\0';
    strcat(even, odd);
    printf("processed sequence: %s", even);
    return 0;
}
