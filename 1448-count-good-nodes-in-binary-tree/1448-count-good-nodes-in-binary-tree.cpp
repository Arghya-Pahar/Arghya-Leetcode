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
    int count(TreeNode* root,int maxi)
    {
        if(root==NULL)
        {
           return 0; 
        }
        int incld=0;
        if(root->val>=maxi)
        {
            incld=1;
        }
        maxi=max(root->val,maxi);
        int left=count(root->left,maxi);
        int right=count(root->right,maxi);
        return incld+left+right;
    }
    int goodNodes(TreeNode* root) {
        return count(root,INT_MIN);
    }
   
};