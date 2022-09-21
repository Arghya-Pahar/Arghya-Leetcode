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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long int>> que;
        que.push({root,0});
        int ans=INT_MIN;
        while(que.size()!=0)
        {
            int n=que.size();
            int lm=que.front().second;
            int rm=que.front().second;
            while(n--)
            {
                TreeNode *cn=que.front().first;
                int idx=que.front().second;
                rm=idx;
                if(cn->left!=NULL)
                {
                    que.push({cn->left,(long long)2*idx+1});
                }
                if(cn->right!=NULL)
                {
                    que.push({cn->right,(long long)2*idx+2});
                }
                que.pop();
            }
            ans=max(ans,rm-lm+1);
        }
        return ans;
        
    }
};