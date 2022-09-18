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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>> que;
        que.push({root,0});
        map<int,vector<int>> mp;
        vector<vector<int>> ans;
        while(que.size()!=0)
        {
            int n=que.size();
            map<int,vector<int>> mp1;
            while(n--)
            {
                TreeNode *cn=que.front().first;
                int dir=que.front().second;
                if(mp1.find(dir)==mp1.end())
                {
                    vector<int> store;
                    mp1.insert({dir,store});
                    mp1[dir].push_back(cn->val);
                }
                else
                {
                    mp1[dir].push_back(cn->val);
                }
                if(cn->left!=NULL)
                {
                    que.push({cn->left,dir-1});
                }
                if(cn->right!=NULL)
                {
                    que.push({cn->right,dir+1});
                }
                que.pop();
            }
            for(auto it=mp1.begin();it!=mp1.end();it++)
            {
                vector<int> s=it->second;
                int var=it->first;
                sort(s.begin(),s.end());
                if(mp.find(var)==mp.end())
                {
                    vector<int> ss;
                    mp.insert({var,ss});
                }
                for(int i=0;i<s.size();i++)
                {
                    mp[var].push_back(s[i]);
                }
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
        
    }
};