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
    int ans=INT_MIN;
    int sum(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lv=sum(root->left);
        int rv=sum(root->right);
        int include;
        if(lv>=0 && rv>=0)
        {
            include=lv+rv+root->val;
        }
        else if(lv>0)
        {
            include=root->val+lv;
        }
        else if(rv>0)
        {
            include=root->val+rv;
            
        }
        else
        {
            include=root->val;
        }
        int notinclude=max(max(lv,rv)+root->val,root->val);
        ans=max(ans,include);
        return notinclude;
        
    }
        
    int maxPathSum(TreeNode* root) {
       int k= sum(root);
        return ans;
        
        
    }
};