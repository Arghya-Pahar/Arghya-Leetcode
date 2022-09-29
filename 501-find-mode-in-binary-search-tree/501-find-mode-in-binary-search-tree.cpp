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
    map<int,int> mp;
    void preorder(TreeNode*root)
    {
        if(root==NULL)
        {
            return ;
        }
        mp[root->val]++;
        preorder(root->left);
        preorder(root->right);
        
    }
    vector<int> findMode(TreeNode* root) {
        preorder(root);
        vector<int> ans;
        int maxi=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            maxi=max(maxi,it->second);
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==maxi)
            {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};