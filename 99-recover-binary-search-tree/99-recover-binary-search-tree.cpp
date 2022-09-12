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
    TreeNode *getrightmostnode(TreeNode *lc,TreeNode* cur)
    {
        while(lc->right!=NULL && lc->right!=cur)
        {
            lc=lc->right;
        }
        return lc;
    }
    void recover(TreeNode *root)
    {
        TreeNode *cur=root,*a=NULL,*b=NULL,*prev=NULL;
        while(cur!=NULL)
        {
            TreeNode *lc=cur->left;
            if(lc==NULL)
            {
                if(prev!=NULL && prev->val>cur->val)
                {
                    if(a==NULL)
                    {
                        a=prev;
                    }
                    b=cur;
                }
                prev=cur;
                cur=cur->right;
            }
            else
            {
                TreeNode *rmn=getrightmostnode(lc,cur);
                if(rmn->right==NULL)
                {
                    rmn->right=cur;
                    cur=cur->left;
                }
                else
                {
                    if(prev!=NULL && prev->val>cur->val)
                    {
                        if(a==NULL)
                        {
                            a=prev;
                        }
                        b=cur;
                    }
                    prev=cur;
                    cur=cur->right;
                    rmn->right=NULL;
                }
            }
            
        }
        swap(a->val,b->val);
    }
    void recoverTree(TreeNode* root) {
        recover(root);
        
    }
};