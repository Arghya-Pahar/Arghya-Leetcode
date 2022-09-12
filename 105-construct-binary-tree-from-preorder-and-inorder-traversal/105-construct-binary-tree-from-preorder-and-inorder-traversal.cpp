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
    TreeNode *build(vector<int> &preorder ,vector<int> & inorder,int ps,int pe,int is,int ie)
    {
        if(ps>pe)
        {
            return NULL;
        }
        int idx=is;
        while(preorder[ps]!=inorder[idx])
        {
            idx++;
        }
        int elem=idx-is;
        TreeNode *node=new TreeNode(preorder[ps]);
        node->left=build(preorder,inorder,ps+1,ps+elem,is,idx-1);
        node->right=build(preorder,inorder,ps+elem+1,pe,idx+1,ie);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return build(preorder,inorder,0,n-1,0,n-1);
    }
};