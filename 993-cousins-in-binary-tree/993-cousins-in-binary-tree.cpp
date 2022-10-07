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
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *p1=NULL,*p2=NULL;
        int l1,l2;
        queue<TreeNode*> que;
        que.push(root);
        int level=0;
        while(que.size()!=0)
        {
            int n=que.size();
            level++;
            while(n--)
            {
                TreeNode* cn=que.front();
                if(cn->val==x)
                    l1=level;
                if(cn->val==y)
                    l2=level;
                if(cn->left!=NULL)
                {
                    if(cn->left->val==x)
                    {
                        p1=cn;
                    }
                    else if(cn->left->val==y)
                    {
                        p2=cn;
                    }
                    que.push(cn->left);
                }
                if(cn->right!=NULL)
                {
                    if(cn->right->val==x)
                    {
                        p1=cn;
                    }
                    else if(cn->right->val==y)
                    {
                        p2=cn;
                    }
                    que.push(cn->right);
                }
                que.pop();
            }
        }
        if(p2!=p1)
        {
            if(l1==l2)
                return true;
            else
                return false;
        }
        
        return false;
    }
};