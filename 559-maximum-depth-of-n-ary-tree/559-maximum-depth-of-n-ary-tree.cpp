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
    int maxDepth(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node*> que;
        que.push(root);
        int level=0;
        while(que.size()!=0)
        {
            int n=que.size();
            level++;
            while(n--)
            {
                Node* n=que.front();
                vector<Node*> store=n->children;
                for(Node* i:store)
                {
                    que.push(i);
                }
                que.pop();
            }
        }
        return level;
        
    }
};