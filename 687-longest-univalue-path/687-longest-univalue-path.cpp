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
    int ans=0;
    pair<int,int> univalue(TreeNode *root)
    {
        if(root==NULL)
        {
            pair<int,int> base;
            base.first=INT_MAX;
            base.second=0;
            return base;
        }
        pair<int,int> l=univalue(root->left);
        pair<int,int> r=univalue(root->right);
        pair<int,int> p;
        p.first=root->val;
        p.second=1;
        if(l.first==root->val && r.first==root->val)
        {
            ans=max(ans,l.second+r.second+1);
            p.second=max(1,max(l.second,r.second)+1);
        }
        else if(l.first==root->val)
        {
            p.second+=l.second;
            ans=max(ans,max(p.second,r.second));
            
        }
        else if(r.first==root->val)
        {
            p.second+=r.second;
            ans=max(ans,max(p.second,l.second));    
        }
        else
        {
            ans=max(ans,1);
            p.second=1;
        }
        return p;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)
            return 0;
        pair<int,int> k=univalue(root);
        return ans-1;
    }
};