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
    bool sym(TreeNode *ltree,TreeNode* rtree)
    {
        if(ltree==NULL || rtree==NULL)
        {
            return ltree==rtree;
        }
        if(ltree->val!=rtree->val)
        {
            return false;
        }
        return sym(ltree->left,rtree->right)&&sym(ltree->right,rtree->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return sym(root->left,root->right);
        
        
    }
};