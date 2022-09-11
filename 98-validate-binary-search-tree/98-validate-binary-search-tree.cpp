/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *prev=NULL;
    bool isBST(TreeNode *root)
    {
        if(root==NULL)
        {
            return true;
        }
        bool lc=isBST(root->left);
        if(lc==false)
        {
            return false;
        }
        if(prev!=NULL && root->val<=prev->val)
        {
            return false;
        }
        prev=root;
        bool rc=isBST(root->right);
        if(rc==false)
        {
            return false;
        }
        return true;
        
    }
    bool isValidBST(TreeNode* root) {
        bool ans=isBST(root);
        return ans;
    }
};