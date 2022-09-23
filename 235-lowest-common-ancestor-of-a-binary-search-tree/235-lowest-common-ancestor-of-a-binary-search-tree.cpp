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
    TreeNode *ans=NULL;
    void lca(TreeNode *root,TreeNode *p,TreeNode *q)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            if(root->val<p->val&&root->val<q->val)
            {
                lca(root->right,p,q);
            }
            else if(root->val>p->val&&root->val>q->val)
            {
                lca(root->left,p,q);
            }
            else
            {
                cout<<root->val<<" ";
                ans=root;
                
            }
            
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        lca(root,p,q);
        return ans;
    }
};