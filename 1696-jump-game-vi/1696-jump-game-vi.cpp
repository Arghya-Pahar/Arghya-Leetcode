class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> que;
        que.push({dp[0],0});
        for(int i=1;i<dp.size();i++)
        {
            while(que.size()!=0 && que.top().second<i-k)
            {
                que.pop();
            }
            dp[i]=que.top().first+nums[i];
            que.push({dp[i],i});
        }
        return dp[nums.size()-1];
    }
};