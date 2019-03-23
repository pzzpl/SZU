#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592
/*
k凸边形求最大R问题：二分法
*/
float f(float r,int *arr,int n){//目标函数
    float result;
    int i;
    for(i=0;i<n;i++){
        result += acos(arr[i]/2*r);
    }
    result -= 2*PI;
    return result;
}
{//求n条边最大的最值
float getMaxArc(int *arr,int n)
    int max = 1e-10;

    int i;
    for(i=0;i<n;i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

float myAbs(float x){
    return x<0?-x:x;
}

int main()
{
    //输入n和n条边
    int n,i;
    scanf("%d",&n);
    int arcs[n];
    for(i=0;i<n;i++){
        scanf("%d",arcs+i);
    }
    //二分
    float x1 = 0.0;;
    float x2 = getMaxArc(arcs,n);
    float mid ;
    float fx1;
    float fmid ;
    while(myAbs(x1-x2) > 1e-6){
            mid = (x1+x2)/2;
            fmid = f(mid,arcs,n);
            fx1 = f(x1,arcs,n);
        if(fx1 * fmid <0){
            x2 = mid;
        }else {
            x1 = mid;
            fx1 = mid;
        }

    }

    printf("%f",mid);
    return 0;
}
