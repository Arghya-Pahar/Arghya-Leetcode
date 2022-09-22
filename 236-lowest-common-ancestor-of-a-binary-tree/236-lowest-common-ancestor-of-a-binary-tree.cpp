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
    TreeNode* lca(TreeNode *root,TreeNode* p,TreeNode *q)
    {
        if(root==NULL || root==p || root==q)
        {
            return root;
        }
        TreeNode *lc=lca(root->left,p,q);
        TreeNode *rc=lca(root->right,p,q);
        if(lc==NULL)
        {
            return rc;
        }
        else if(rc==NULL)
        {
            return lc;
        }
        else
        {
            return root;
        }
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=lca(root,p,q);
        return ans;
    }
};