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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int ans;
        while(que.size()!=0)
        {
            ans=que.front()->val;
            int n=que.size();
            while(n--)
            {
                TreeNode *cn=que.front();
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
        return ans;
    }
};