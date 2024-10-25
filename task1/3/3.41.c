#include <stdio.h>
#include <math.h>

int main(void){
    double eps; 
    scanf("%lf", &eps);
    double a = 0.0;
    double b = sqrt(0.5); 
    double approx; 
    long double pi;
    approx = b;
    while (fabs(b - a) > eps){
        a = b;
        b = sqrt((0.5) + (0.5 * a));
        approx = approx * b;
    }
    pi = (2.0) / approx;
    printf("%Lf\n", pi);
    return 0;
}
