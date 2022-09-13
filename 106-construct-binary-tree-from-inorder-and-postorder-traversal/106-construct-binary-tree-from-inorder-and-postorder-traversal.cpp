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
    TreeNode* build(vector<int> &inorder,vector<int> &postorder,int is,int ie,int ps,int pe)
    {
        if(is>ie)
        {
            return NULL;
        }
        int idx=is;
        while(inorder[idx]!=postorder[pe])
        {
            idx++;
        }
        int elem=idx-is;
        TreeNode *node=new TreeNode(postorder[pe]);
        node->left=build(inorder,postorder,is,idx-1,ps,ps+elem-1);
        node->right=build(inorder,postorder,idx+1,ie,ps+elem,pe-1);
        return node;
        
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size()-1;
        return build(inorder,postorder,0,n,0,n);
    }
};