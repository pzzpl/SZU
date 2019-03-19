/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<TreeNode*> queue;
        vector<vector<int> > res;
        if(!root) return res;
        vector<int> tmp;
        queue.push_back(root);
        queue.push_back(NULL);
        TreeNode* p;
        int i = 0;
        while(queue.front() != NULL){
            p = queue.front();
            tmp.push_back(p->val);
            if(p->left)
                queue.push_back(p->left);
            if(p->right)
                queue.push_back(p->right);
            queue.erase(queue.begin());
            p = queue.front();
            if(p == NULL){
                queue.erase(queue.begin());
                p = queue.front();
                res.push_back(tmp);
                tmp.clear();
                queue.push_back(NULL);
            }
        }
        return res;
    }
};