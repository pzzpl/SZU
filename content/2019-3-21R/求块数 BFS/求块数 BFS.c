#include<stdio.h>
    int arr[][7] = {{0,1,0,1,0,0,1},
                    {0,0,1,0,0,0,0},
                    {0,0,0,0,1,0,0},
                    {0,0,0,1,1,1,0},
                    {0,1,0,0,1,0,0},
                    {1,0,1,1,0,0,0}};

    int queue[255][2];        //队列保存位置坐标
    int head = 0,  rear = 0;

    int w = sizeof(arr[0])/4;
    int h = sizeof(arr) / sizeof(arr[0]);

void BFSblock(int arr2[][w], int i, int j){
    queue[rear][0] = i;
    queue[rear][1] = j;
    rear++;
    while(head != rear){
        i = queue[head][0];
        j = queue[head][1];
        arr2[i][j] = 0;
        if(i+1 < h && arr2[i+1][j] == 1) {      //down
            queue[rear][0] = i+1;
            queue[rear][1] = j;
            rear++;
        }
        if(i-1 >= 0 && arr2[i-1][j] == 1) {      //up
            queue[rear][0] = i-1;
            queue[rear][1] = j;
            rear++;
        }
        if(j+1 < w && arr2[i][j+1] == 1) {      //left
            queue[rear][0] = i;
            queue[rear][1] = j+1;
            rear++;
        }
        if(j-1 >= 0 && arr2[i][j-1] == 1) {      //right
            queue[rear][0] = i;
            queue[rear][1] = j-1;
            rear++;
        }
        head++;
    }
}

int main(){

    int count = 0;
    int arr2[h][w];
    for(int i = 0; i < h; i++){     ///复制这个数组
        for(int j = 0; j < w; j++){
            arr2[i][j] = arr[i][j];
        }
    }
    for(int i = 0; i < h; i++){         ///找到块
        for(int j = 0; j < w; j++){
            if(arr2[i][j] == 1){
                BFSblock(arr2, i, j);   ///广度遍历将这个块换成0
                count++;
            }
        }
    }
    printf("There are %d blocks\n", count);
}
