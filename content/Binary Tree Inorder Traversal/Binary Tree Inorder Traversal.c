/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**/
void get_inorder(int* returnSize,int* res,struct TreeNode* root){
    if(!root)
        return;
    get_inorder(returnSize,res,root->left);
    res[*returnSize] = root->val;
    ++*returnSize;
    get_inorder(returnSize,res,root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    * returnSize = 0;
    int res[255];
    get_inorder(returnSize, res, root);
    int bs=sizeof(int)*(*returnSize);
	int *ret=malloc(bs);
	memcpy(ret,res,bs);
    return ret;
}