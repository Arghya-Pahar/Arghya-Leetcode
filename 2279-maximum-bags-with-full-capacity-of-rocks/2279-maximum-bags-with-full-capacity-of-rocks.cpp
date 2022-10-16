class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int n) {
        priority_queue<int,vector<int>,greater<int>> que;
        for(int i=0;i<capacity.size();i++)
        {
            que.push(capacity[i]-rocks[i]);
        }
        int count=0;
        while(que.size()!=0 && n-que.top()>=0)
        {
            
            n=n-que.top();
            count++;
            que.pop();
        }
        return count;
    }
};