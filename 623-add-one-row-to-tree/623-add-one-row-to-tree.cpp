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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        vector<TreeNode*> ans;
        queue<TreeNode*> que;
        que.push(root);
        if(depth==1)
        {
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        int level=0;
        while(que.size()!=0)
        {
            int n=que.size();
            vector<TreeNode*> temp;
            level++;
            if(level==depth)
            {
                break;
            }
            while(n--)
            {
                TreeNode* cn=que.front();
                temp.push_back(cn);
                if(cn->left!=NULL)
                {
                    que.push(cn->left);
                }
                if(cn->right!=NULL)
                {
                    que.push(cn->right);
                }
                que.pop();
            }
            ans=temp;
        }
        for(int i=0;i<ans.size();i++)
        {
            TreeNode* cn=ans[i];
            TreeNode* l=cn->left;
            TreeNode* r=cn->right;
            TreeNode* node1=new TreeNode(val);
            TreeNode* node2=new TreeNode(val);
            cn->left=node1;
            cn->right=node2;
            node1->left=l;
            node2->right=r;
        }
        return root;
        
    }
};