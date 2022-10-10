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
    vector<int> ans1;
    void inorder1(TreeNode *root1)
    {
        if(root1==NULL)
        {
            return;
        }
        inorder1(root1->left);
        ans1.push_back(root1->val);
        inorder1(root1->right);
    }
    void inorder2(TreeNode *root2)
    {
        if(root2==NULL)
        {
            return;
        }
        inorder2(root2->left);
        ans1.push_back(root2->val);
        inorder2(root2->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder1(root1);
        inorder2(root2);
        sort(ans1.begin(),ans1.end());
        return ans1;
    }
};