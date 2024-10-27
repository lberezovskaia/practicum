#include <stdio.h>
#include <string.h>
#define n1 25
#define n2 40

void G(double *mas, int n, double *min, double *max){
    *min = *mas;
    *max = *mas;
    for (int i = 0; i < n; i++){
        if (mas[i] < *min){
            *min = *(mas + i);
        }
        if (mas[i] > *max){
            *max = *(mas + i);
        }
    }    
}

int main(void){
    double x[n1];
    double y[n2];
    double min1, max1, min2, max2;
    // реализация заполнения массива x и нахождения его min и max
    printf("enter the elements of the array x: \n");
    for (int i = 0; i < n1; i++){
        printf("x[%d] = ", i);
        scanf("%lf", &*(x + i));
    }
    G(x, n1, &min1, &max1);
    printf("min of the array x: %lf\n", min1);
    printf("max of the array x: %lf\n", max1);
    printf("\n");
    // реализация заполнения массива y и нахождения его min и max
    printf("enter the elements of the array y: \n");
    for (int i = 0; i < n2; i++){
        printf("y[%d] = ", i);
        scanf("%lf", &*(y + i));
    }
    G(y, n2, &min2, &max2);
    printf("min of the array y: %lf\n", min2);
    printf("max of the array y: %lf\n", max2);
    return 0;
}
