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
    void kdown(TreeNode *root,int k,TreeNode* blocknode,vector<int> &ans)
    {
        if(root==NULL || k<0 || root==blocknode)
        {
            return;
        }
        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }
        kdown(root->left,k-1,blocknode,ans);
        kdown(root->right,k-1,blocknode,ans);
    }
    int distance(TreeNode *root,int target,int k,vector<int> &ans)
    {
        if(root==NULL)
        {
            return -1;
        }
        if(root->val==target)
        {
            kdown(root,k,NULL,ans);
            return 1;
        }
        int ld=distance(root->left,target,k,ans);
        if(ld>0)
        {
            kdown(root,k-ld,root->left,ans);
            return ld+1;
        }
        int rd=distance(root->right,target,k,ans);
        if(rd>0)
        {
            kdown(root,k-rd,root->right,ans);
            return rd+1;
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        int c=distance(root,target->val,k,ans);
        return ans;
        
    }
};