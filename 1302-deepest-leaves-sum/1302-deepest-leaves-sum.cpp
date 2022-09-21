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
    int deepestLeavesSum(TreeNode* root) {
       queue<TreeNode*> que;
       if(root==NULL)
       {
           return 0;
       }
       que.push(root);
       vector<int> ans;
       while(que.size()!=NULL)
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
               if(cn->right!=NULL)
               {
                   que.push(cn->right);
               }
               que.pop();
               
           }
           ans=store;
       }
       int sum=0;
        for(int i=0;i<ans.size();i++)
        {
            sum+=ans[i];
        }
        return sum;
        
    }
};