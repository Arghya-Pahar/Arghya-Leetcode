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
    TreeNode* build(vector<int>& preorder,vector<int> &postorder,int prest,int prend,int postst,int postend)
    {
        if(prest>prend)
        {
            return NULL;
        }
        TreeNode *node=new TreeNode(preorder[prest]);
        if(prest==prend)
        {
            return node;
        }
        int idx=postst;
        while(postorder[idx]!=preorder[prest+1])
        {
            idx++;
        }
        int elem=idx-postst+1;
        
        node->left=build(preorder,postorder,prest+1,prest+elem,postst,idx);
        node->right=build(preorder,postorder,prest+elem+1,prend,idx+1,postend-1);
        return node;
    }
        
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size()-1;
        return build(preorder,postorder,0,n,0,n);
    }
};