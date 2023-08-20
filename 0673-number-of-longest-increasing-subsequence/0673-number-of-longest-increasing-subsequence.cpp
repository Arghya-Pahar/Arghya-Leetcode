class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size());
        dp[0].first=1;
        dp[0].second=1;
        int vali=1,ans=0;
        map<int,int> mp;
        cout<<dp[0].first<<" "<<dp[0].second;
        cout<<endl;
        for(int i=1;i<nums.size();i++)
        {
            priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    pq.push({dp[j].first,dp[j].second});

                }
            }
            int sum=0;
            int maxi=INT_MIN;
            int len=0;
            while(pq.size()!=0)
            {
                int val=pq.top().first;
                int no=pq.top().second;
                
                if(val>=maxi)
                {
                    sum+=no;
                    maxi=val;
                    len=val;
                }
                else
                {
                    break;
                }
                pq.pop();


            }
            dp[i].first=len+1;
            if(sum!=0)
            {
            dp[i].second=sum;
            }
            else
            {
                dp[i].second=1;
            }
            cout<<dp[i].first<<" "<<dp[i].second;
            cout<<endl;
            vali=max(vali,dp[i].first);
           
        }
        for(int i=0;i<dp.size();i++)
        {
            if(dp[i].first==vali)
            {
                ans+=dp[i].second;
            }
        }

        return ans;
    }
};