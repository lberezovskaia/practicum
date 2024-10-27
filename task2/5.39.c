#include <stdio.h>

int cyclic_shift(int *mas, int m, int n){
    int fix;
    for (int i = 0; i < n; i++){
        fix = *mas;
        for (int j = 0; j < m - 1; j++){
            *(mas + j) = *(mas + j + 1);
        }
        *(mas + m - 1) = fix;
    }
    return *mas;
}

int main(void){
    int n;
    int m;
    printf("enter the number of array elements: ");
    scanf("%d", &m);
    int a[m];
    printf("enter the elements of the array: \n");
    for (int i = 0; i < m; i++){
        printf("x[%d] = ", i);
        scanf("%d", &*(a + i));
    }
    printf("\n");
    printf("enter the number of shifts to the left: ");
    scanf("%d", &n);
    *a = cyclic_shift(a, m, n);
    printf("processed array: \n");
    for (int i = 0; i < m; i++){
        printf("x[%d] = ", i);
        printf("%d\n", *(a + i));
    }
    return 0;
}
