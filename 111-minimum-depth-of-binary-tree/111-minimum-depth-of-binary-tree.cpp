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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if(root!=NULL)
        que.push(root);
        int level=0;
        while(que.size()!=0)
        {
            
            int n=que.size();
            level++;
            while(n--)
            {
                TreeNode *cn=que.front();
                bool flag1=false,flag2=false;
                if(cn->left!=NULL)
                {
                    que.push(cn->left);
                    flag1=true;
                }
                if(cn->right!=NULL)
                {
                    que.push(cn->right);
                    flag2=true;
                }
                if(flag1==false && flag2==false)
                {
                    return level;
                }
                que.pop();
            }
            
        }
        return level;
        
    }
};