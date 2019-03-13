#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 4
#define N 5
#define MIN -10000
#define MAX 10000
//saddle point

int getMaxIndex(int *arr,int n){
    int max,maxIndex;
    int i;
    max = MIN;
    maxIndex = 0;

    for(i=0;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

int isMinCol(int (*tar)[M],int col,int row){
    int j;
    int min = MAX;
    int minIndex;
    for(j=0;j<N;j++){
        int temp = *(*(tar+j)+col);
        if(temp < min ){
            min = temp;
            minIndex = j;
        }
    }
    if(minIndex == row)
        return 1;
    else
        return 0;
}
int main()
{
    int matrix[N][M] = {
        21,32,45,9,6,8,7,8,7,64,5,424,23,42,4,2,6,8765,5,12
    };
    int i;
    int saddle_x,saddle_y;
    for(i=0;i<N;i++){
        saddle_y = getMaxIndex(matrix[i],N);
        //判断列是否最小
        if(isMinCol(matrix,saddle_y,i)){
            saddle_x = i;
            printf("saddle point is [%d,%d]",saddle_x,saddle_y);
        }
    }

    return 0;
}

