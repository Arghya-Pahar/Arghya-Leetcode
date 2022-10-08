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
    vector<int> sorted;
    void inorder(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        sorted.push_back(root->val);
        inorder(root->right);
    }
    TreeNode *bst(vector<int> &nums,int left,int right)
    {
        if(left>right)
        {
          return NULL;  
        }
        int mid=left+(right-left)/2;
        TreeNode *node=new TreeNode(nums[mid]);
        node->left=bst(nums,left,mid-1);
        node->right=bst(nums,mid+1,right);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        TreeNode *ans=bst(sorted,0,sorted.size()-1);
        return ans;
    }
};