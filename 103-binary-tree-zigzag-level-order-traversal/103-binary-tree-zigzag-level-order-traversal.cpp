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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> pst;
        if(root!=NULL)
        pst.push(root);
        int flag=1;
        while(pst.size()!=0)
        {
            int n=pst.size();
            stack<TreeNode*> cst;
            vector<int> store;
            flag++;
            while(n--)
            {
                TreeNode *cn=pst.top();
                store.push_back(cn->val);
                if(flag%2==0)
                {
                    if(cn->left!=NULL)
                    {
                        cst.push(cn->left);
                    }
                    if(cn->right!=NULL)
                    {
                        cst.push(cn->right);
                    }
                }
                else
                {
                    if(cn->right!=NULL)
                    {
                        cst.push(cn->right);
                    }
                    if(cn->left!=NULL)
                    {
                        cst.push(cn->left);
                    }
                }
                pst.pop();
                
            }
            ans.push_back(store);
            pst=cst;
            
        }
        return ans;
    }
};