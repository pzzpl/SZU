/*冒泡排序*/

#include<stdio.h>
#include<stdbool.h> //使用此头文件可以像c++一样正常使用bool型
//#define false 0
//#define true 1
void bubbleSort(int arr[], int len);

int main(){
    int arr[] = {4,2,7,6,4,8,9,1,0};
    printf("the origin array is: ");
    int len = 9;
    for(int i = 0; i < len; i++){
        printf(i == len -1 ? "%d\n" : "%d ",arr[i]);
    }
    printf("BubbleSort\n");
    bubbleSort(arr, len);
    for(int i = 0; i < len; i++){
        printf(i == len -1 ? "%d\n" : "%d ",arr[i]);
    }
    return 0;

}

void bubbleSort(int arr[], int len){
    bool tag = false;
    for(int i = 0; i < len-1;i++){
        if(arr[i] < arr[i+1]){
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
            tag  = true;
        }
    }
    if(tag)
        bubbleSort(arr, len-1);
    return;
}
