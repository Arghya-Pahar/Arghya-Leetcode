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
    vector<int> preorder(TreeNode *root,vector<int> &ans)
    {
        if(root==NULL)
        {
            return {};
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                ans.push_back(root->val);
            }
            preorder(root->left,ans);
            preorder(root->right,ans);
            
        }
        return ans;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a1;
        vector<int> a2;
        vector<int> ans1=preorder(root1,a1);
        vector<int> ans2=preorder(root2,a2);
        if(ans1==ans2)
            return true;
        else
            return false;
        
        
    }
};