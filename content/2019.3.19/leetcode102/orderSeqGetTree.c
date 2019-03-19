#include <stdio.h>
#include <stdlib.h>
#include "common.h"
/*
struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *    struct TreeNode *right;
  };
  */
//由前序和中序遍历序列，确认一棵树
struct TreeNode *createBT(char *pre,char *in,int L1,int R1,int L2,int R2){
    if(L1 > R1)
        return NULL;
    struct TreeNode *result = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    result -> left = NULL;
    result -> right = NULL;
    result -> val = pre[L1] - '0';
    //寻找根
    int i;
    for(i=L2;i<R2;i++)
        if(in[i] == pre[L1])
            break;

    result -> left = createBT(pre,in,L1+1,L1+i-L2,L2,i-1);
    result -> right = createBT(pre,in,L1+i-L2+1,R1,i+1,R2);

    return result;
}
