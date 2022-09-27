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
    TreeNode* ans;
    void dfs(TreeNode* root1,TreeNode* root2,TreeNode* target)
    {
        if(root1==NULL)
        {
            return ;
        }
        if(root1->val==target->val)
        {
            ans=root2;
            return;
        }
        dfs(root1->left,root2->left,target);
        dfs(root1->right,root2->right,target);
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original,cloned,target);
        return ans;
    }
};