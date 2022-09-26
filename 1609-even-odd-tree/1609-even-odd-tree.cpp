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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int level=-1;
        while(que.size()!=0)
        {
            int n=que.size();
            level++;
            if(level%2==0)
            {
                int prev=INT_MIN;
                while(n--)
                {
                    TreeNode *cn=que.front();
                    int data=cn->val;
                    if(data<=prev || data%2==0)
                    {
                        return false;
                    }
                    else
                    {
                        prev=data;
                    }
                    if(cn->left!=NULL)
                    {
                        que.push(cn->left);
                    }
                    if(cn->right!=NULL)
                    {
                        que.push(cn->right);
                    }
                    que.pop();
                }
            }
            else
            {
                int prev=INT_MAX;
                while(n--)
                {
                    TreeNode *cn=que.front();
                    int data=cn->val;
                    cout<<data<<" ";
                    if(data>=prev || data%2!=0)
                    {
                        return false;
                    }
                    else
                    {
                        prev=data;
                    }
                    if(cn->left!=NULL)
                    {
                        que.push(cn->left);
                    }
                    if(cn->right!=NULL)
                    {
                        que.push(cn->right);
                    }
                    que.pop();
                }
                
                
            }
            cout<<endl;
        }
        return true;
        
    }
};