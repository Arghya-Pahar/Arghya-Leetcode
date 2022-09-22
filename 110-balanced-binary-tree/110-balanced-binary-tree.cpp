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
    bool flag=true;
    int balanced(TreeNode* root)
    {
        if(root==NULL)
        {
            return -1;
            
        }
        int ls=balanced(root->left);
        int rs=balanced(root->right);
        if(abs(ls-rs)>1)
        {
            flag=false;
        }
        return max(ls,rs)+1;
        
    }
    bool isBalanced(TreeNode* root) {
        balanced(root);
        return flag;
        
    }
};