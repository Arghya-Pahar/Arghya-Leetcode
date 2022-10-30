class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int i=0;i<stones.size();i++)
        {
            sum+=stones[i];
        }
        int n=stones.size();
        int m=sum/2;
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
        int ans=0;
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=true;
                }
                else if(i==0)
                {
                    dp[i][j]=false;
                }
                else if(j==0)
                {
                    dp[i][j]=true;
                }
                else
                {
                    if(dp[i-1][j]==true)
                    {
                        dp[i][j]=true;
                    }
                    else if(stones[i-1]<=j)
                    {
                        if(dp[i-1][j-stones[i-1]])
                        {
                            dp[i][j]=true;
                        }
                    }
                }
                
                if(i==dp.size()-1)
                {
                    if(dp[i][j])
                    {
                        ans=j;
                    }
                }
            }
            
        }
        int temp=sum-ans;
        return abs(temp-ans);
    }
};