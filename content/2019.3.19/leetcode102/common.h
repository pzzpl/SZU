struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };



struct TreeNode *createBT(char *pre,char *in,int L1,int R1,int L2,int R2);
