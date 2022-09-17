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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        if(root!=NULL)
        que.push(root);
        vector<vector<int>> ans;
        while(que.size()!=0)
        {
            int n=que.size();
            vector<int> store;
            while(n--)
            {
                TreeNode *cn=que.front();
                store.push_back(cn->val);
                if(cn->left!=NULL)
                {
                    que.push(cn->left);
                }
                if(cn->right)
                {
                    que.push(cn->right);
                }
                que.pop();
            }
            ans.push_back(store);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};