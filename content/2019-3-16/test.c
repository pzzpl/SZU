#include <stdio.h>
#include <stdlib.h>

double method2(){
    int i;
    double sum = 0.0;
    for(i=100;i>=1;i++){
        sum += (double)1/i;
    }
    return sum;
}
double method1(){
    int i;
    double sum = 0.0;
    for(i=1;i<=100;i++){
        double temp = (double)1/i;
        //printf("%f\n",temp);
        sum += temp;
    }
    return sum;
}

int main()
{
    double m1 = method1();
    double m2 = method2();
    printf("%.2f\n",m1);
    printf("%.2f\n",m2);
    return 0;
}
