/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* subl, struct TreeNode* subr);

bool isSymmetric(struct TreeNode* root) {
    if(!root)
        return true;
    return isMirror(root->left, root->right);
}
bool isMirror(struct TreeNode* subl, struct TreeNode* subr){
    if(!subl && !subr) return true;
    if(!subl || !subr) return false;
    if(subl->val != subr->val) return false;
    if(isMirror(subl->left,subr->right)){
        return isMirror(subl->right,subr->left);
    }
    else
        return false;
}