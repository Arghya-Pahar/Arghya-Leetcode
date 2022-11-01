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
    TreeNode* deletee(TreeNode *root,int k)
    {
        if(root==NULL)
        {
            return NULL;
        }
        else
        {
            root->left=deletee(root->left,k);
            root->right=deletee(root->right,k);
            if(root->val==k && root->left==NULL && root->right==NULL)
            {
                return NULL;
            }
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL)
            return NULL;
        TreeNode *ans=deletee(root,target);
        return ans;
    }
};