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
    vector<TreeNode*> create(int st,int end)
    {
        if(st>end)
        {
            vector<TreeNode*> base;
            base.push_back(NULL);
            return base;
        }
        vector<TreeNode*> ans;
        for(int i=st;i<=end;i++)
        {
            vector<TreeNode*> left=create(st,i-1);
            vector<TreeNode*> right=create(i+1,end);
            for(TreeNode* l:left)
            {
                for(TreeNode* r:right)
                {
                        TreeNode* node=new TreeNode(i);
                        node->left=l;
                        node->right=r;
                        ans.push_back(node);
                        
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans=create(1,n);
        return ans;
    }
};