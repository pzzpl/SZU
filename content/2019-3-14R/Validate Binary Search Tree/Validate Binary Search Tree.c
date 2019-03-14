#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
// 建立二叉树
struct TreeNode * CreateBitree(struct TreeNode *root){
    int ch;
    scanf("%d",&ch);
    if(ch==0)
    {
        root=NULL;
        printf("a null!\n");
        return(root);
    }
    else
    {
        root=(struct TreeNode* )malloc(sizeof(struct TreeNode));
        root->val=ch;
        printf("root = %d\n", root->val);
        root->left = CreateBitree(root->left);              //注意此句等号前面不能省略，省略则对左右子树做的修改无效
        root->right = CreateBitree(root->right);        //检查这个我耽搁了很久
        return(root);
    }
}
//判断是否为BST
bool _isValidBST(struct TreeNode* root, int *min, int *max)
{
    if (!root)
        return 1;
    if (min && root->val <= *min) //当前子树根节点小于等于最小值，或大于等于最大值，则此树不是bst
        return 0;
    if (max && root->val >= *max)
        return 0;
    return _isValidBST(root->left, min, &root->val) && _isValidBST(root->right, &root->val, max);//只要其中一颗子树不是bst，该树就不是BST树
}

bool isValidBST(struct TreeNode* root)
{
    return _isValidBST(root, NULL, NULL);
}

int main(){
    struct TreeNode *root;
    printf("this tree would be created by preorder.\n");
    printf("please input each point 's value(with 0 means null) : \n");
    root = CreateBitree(root);
    printf("\n this is a validBST:  ");
    //printf("\n % d", isValidBST(root));
    if(isValidBST(root))
        printf("true");
    else
        printf("false");
}
