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
    int sum=0;
    void preorder(TreeNode * root)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left!=NULL)
        {
            if(root->left->left==NULL && root->left->right==NULL)
            {
                cout<<root->left->val<<" ";
                sum=sum+root->left->val;
            }
        }
        preorder(root->left);
        preorder(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        preorder(root);
        return sum;
        
    }
};