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
    vector<TreeNode*> FBT(int n)
    {
        if(n==1)
        {
            vector<TreeNode*> base;
            TreeNode *node=new TreeNode(0);
            base.push_back(node);
            return base;
        }
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> left=FBT(i);
            vector<TreeNode*> right=FBT(n-i-1);
            for(TreeNode* l:left)
            {
                for(TreeNode* r:right)
                {
                    TreeNode* nodee=new TreeNode(0);
                    nodee->left=l;
                    nodee->right=r;
                    ans.push_back(nodee);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return FBT(n);
    }
};