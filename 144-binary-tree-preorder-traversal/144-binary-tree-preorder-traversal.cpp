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
    TreeNode* rightmostnode(TreeNode *lc,TreeNode *cur)
    {
        TreeNode *rm=lc;
        while(rm->right!=NULL && rm->right!=cur)
        {
            rm=rm->right;
        }
        return rm;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *cur=root;
        vector<int> ans;
        while(cur!=NULL)
        {
            TreeNode *lc=cur->left;
            if(lc==NULL)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode *rm=rightmostnode(lc,cur);
                if(rm->right==NULL)
                {
                    ans.push_back(cur->val);
                    rm->right=cur;
                    cur=cur->left;
                }
                else
                {
                    rm->right=NULL;
                    cur=cur->right;
                }
            }
            
        }
        return ans;
    }
};