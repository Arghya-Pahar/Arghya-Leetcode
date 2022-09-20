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
    int summ=0;
    void sum(TreeNode *root,string s)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            s=s+to_string(root->val);
            summ+=stoi(s);
            return;
            
        }
        sum(root->left,s+to_string(root->val));
        sum(root->right,s+to_string(root->val));
        
        
    }
    int sumNumbers(TreeNode* root) {
        sum(root,"");
        return summ;
        
        
    }
};