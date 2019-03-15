/*报数，每逢5出列，求剩下那个数（数组法）*/

#include<stdio.h>

int main(){
    int n;
    printf("please input a number: ");
    scanf("%d" ,&n);
    int arr[n];
    for(int i = 0; i < n ;i++){
        arr[i] = i+1;   //  用一个数组记录每个人的编号
    }
    for(int i = 0; i < n ;i++){
        printf("%d ",arr[i]);   //  用一个数组记录每个人的编号
    }
    int c = 0;  //  记录出队人数
    int i = 0, k = 0;   //k数5
    while(c < n-1){
            k = 0;
        while(k < 5){
            i = i % n;
            if(arr[i]!=0){
                k++;
            }
            i++;
        }
        arr[i-1] = 0;     //踢出去一个人
        c++;
        i = i%n;
    }
    for(int i = 0; i < n; ++i){
        if(arr[i] != 0){
            printf("\nthe last child is %d\n", arr[i]);
            break;
        }
    }

    return 0;
}
