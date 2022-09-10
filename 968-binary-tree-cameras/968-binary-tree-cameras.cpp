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
    int count=0;
    int camera(TreeNode *root)
    {
        if(root==NULL)
        {
            return 1;
        }
        int lc=camera(root->left);
        int rc=camera(root->right);
        if(lc==-1 ||rc==-1)
        {
            count++;
            return 0;
        }
        if(rc==0 || lc==0)
        {
            return 1;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        
        int c=camera(root);
        if(c==-1)count++;
        return count;
    }
};