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
    pair<int,int> robber(TreeNode *root)
    {
        if(root==NULL)
        {
            pair<int,int> neww;
            neww.first=0;
            neww.second=0;
            return neww;
            
        }
        pair<int,int> lc=robber(root->left);
        pair<int,int> rc=robber(root->right);
        int rob=root->val+lc.second +rc.second;
        int norob=max(lc.first,lc.second)+max(rc.first,rc.second);
        pair<int,int> updated;
        updated.first=rob;
        updated.second=norob;
        return updated;
    }
    int rob(TreeNode* root) {
        pair<int,int> ans=robber(root);
        return max(ans.first,ans.second);
    }
};