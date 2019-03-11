#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 4
#define N 5
#define MIN 1^-3
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

int ** getInverse(int (*a)[M],int r,int c){
    int **result = (int **) malloc(r*sizeof(int *));
    for(int i=0;i<r;i++){
        *(result+i) = (int *)malloc(c*sizeof(int));
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            result[j][i] = a[i][j];
        }
    }
    return result;
}


int main()
{
    int matrix[N][M] = {
        21,32,45,9,6,8,7,8,7,64,5,424,23,42,4,2,6,8765,5,12
    };
    int **inver = getInverse(matrix,5,4);

    for(int i=0;i<N;i++){
        int colNum = getMaxIndex(matrix[i],4);
        int rowNum = getMaxIndex(inver[colNum],5);
        if(rowNum == i){
            printf("saddle point:[%d,%d]\n",i,colNum);
        }
    }
    return 0;
}

