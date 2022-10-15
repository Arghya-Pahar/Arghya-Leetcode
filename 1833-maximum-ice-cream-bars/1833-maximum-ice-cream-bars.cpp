class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int,vector<int>,greater<int>> que;
        for(int i=0;i<costs.size();i++)
        {
            que.push(costs[i]);
        }
        int count=0;
        int sum=0;
        // if(que.top()>coins)
        // {
        //     return 0;
        // }
        while(sum+que.top()<=coins && que.size()!=0)
        {
            int val=que.top();
            cout<<val<<" ";
            count++;
            sum+=val;
            que.pop();
        }
        return count;
    }
};