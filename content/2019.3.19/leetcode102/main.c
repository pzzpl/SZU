#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#define MAXSIZE 50
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//把target中i个元素，mal一个新数组，放到buf中
void attach(int *buf[],int *target,int i,int level){
    int *temp = malloc(sizeof(int)*i);
    int j;//work pointer
    for(j=0;j<i;j++){
        temp[j] = target[j];
    }
    //粘
    buf[level] = temp;

}


int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
        if(!root){
            return NULL;
        }
        struct TreeNode *que[MAXSIZE];
        int *buff[MAXSIZE];//暂时返回值
        int arr1[MAXSIZE];//暂时每层存储结果
        int columnSizesResult[MAXSIZE];//对应columnSizes
        int i = 0;//数一层
        int rear = 0, front = 0;
        int level = 0;
        int last = 1;
        struct TreeNode *p;//工作指针
        //进队一个 不用循环队列了 来个顺序队
        que[rear++] = root;
        //只要队不控 就干下面
        while(rear != front){
            p = que[front++];
            arr1[i++] = p-> val;//暂存
            //把孩子们进队
            if(p ->left )
                que[rear++] = p->left;
            if(p -> right)
                que[rear++] = p->right;
            if(last == front){//出了一层 粘到buff中
                attach(buff,arr1,i,level);

                columnSizesResult[level] = i;//每一层的元素个数

                level++;//一层

                last = rear;

                i = 0;//每层元素个数归0


            }
        }
        //层次遍历结束，数组大小以及确定
        int **result = (int**)malloc(sizeof(int*)*level);
        for(i=0;i<level;i++){
            *(result+i) = *(buff+i);
        }

        int *czResult = (int*)malloc(sizeof(int)*level);
        for(i=0;i<level;i++){
            czResult[i] = columnSizesResult[i];
        }

        *returnSize = level;
        *columnSizes = czResult;
        return result;
}




void inOrder(struct TreeNode *p){
    if(p != NULL){
        inOrder(p->left);
        printf("%d ",p->val);
        inOrder(p->right);
    }
}
//测试
int main()
{
    char *pre = "12453678";
    char *in = "42513786";
    struct TreeNode *root = createBT(pre,in,0,7,0,7);
    //inOrder(root);
    int *columnSizes;
    int returnSize;
    int **result = levelOrder(root,&columnSizes,&returnSize);

    int i ,j;
    for(i=0;i<returnSize;i++){
        for(j=0;j<columnSizes[i];j++){
            printf("%d ",*(*(result+i)+j));
        }
        printf("\n");
    }

    return 0;
}
