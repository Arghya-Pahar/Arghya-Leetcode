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
    vector<int> zigzag(TreeNode * root)
    {
        if(root==NULL)
        {
            vector<int> neww(3,-1);
            neww[2]=0;
            return neww;
        }
        vector<int> lc=zigzag(root->left);
        vector<int> rc=zigzag(root->right);
        vector<int> updt(3);
        updt[2]=max(max(lc[2],rc[2]),max(lc[1],rc[0])+1);
        updt[0]=lc[1]+1;
        updt[1]=rc[0]+1;
        return updt;
    }
    int longestZigZag(TreeNode* root) {
        
        vector<int> ans=zigzag(root);
        return ans[2];
        
    }
};