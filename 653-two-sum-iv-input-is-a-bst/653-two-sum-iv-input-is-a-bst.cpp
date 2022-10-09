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
    set<int> s;
    bool check=false;
    void inorder(TreeNode* root,int tar)
    {
        if(root==NULL)
        {
           return; 
        }
        inorder(root->left,tar);
        if(s.size()!=0)
        {
            if(s.find(tar-root->val)!=s.end())
            {
                check=true;
            }
        }
        if(check==true)
            return;
        s.insert(root->val);
        inorder(root->right,tar);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root,k);
        return check;
    }
};