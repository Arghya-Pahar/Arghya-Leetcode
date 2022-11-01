/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
        {
            return {};
        }
        queue<Node*> que;
        que.push(root);
        vector<vector<int>> ans;
        while(que.size()!=0)
        {
            int n=que.size();
            vector<int> store;
            while(n--)
            {
                Node* curr=que.front();
                store.push_back(curr->val);
                vector<Node*> child=curr->children;
                for(int i=0;i<child.size() && child.size()>0;i++)
                {
                    if(child[i]!=NULL)
                    que.push(child[i]);
                }
                que.pop();
                
            }
            ans.push_back(store);
        }
        return ans;
    }
};