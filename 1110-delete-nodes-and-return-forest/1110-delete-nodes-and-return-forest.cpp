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
    vector<TreeNode*> ans;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        for(int i=0;i<to_delete.size();i++)
        {
            st.insert(to_delete[i]);
        }
        if(st.find(root->val)==st.end())
        {
            ans.push_back(root);
        }
        TreeNode *k=del(root,st);
        return ans;
    }
    TreeNode* del(TreeNode* root,set<int> st)
    {
        if(root==NULL)
        {
            return NULL;
        }
        root->left=del(root->left,st);
        root->right=del(root->right,st);
        if(st.find(root->val)!=st.end())
        {
            if(root->left!=NULL)
            {
                ans.push_back(root->left);
            }
            if(root->right!=NULL)
            {
                ans.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }
};