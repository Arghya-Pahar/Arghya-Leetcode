class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),0));
        int ans=INT_MAX;
        for(int i=0;i<dp.size();i++)
        {
            int first=INT_MAX;
            int second=INT_MAX;
            if(i!=0)
            {
                for(int k=0;k<dp[0].size();k++)
                {
                    if(dp[i-1][k]<first)
                    {
                        second=first;
                        first=dp[i-1][k];
                    }
                    else if(dp[i-1][k]<second)
                    {
                        second=dp[i-1][k];
                    }
                }
            }
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else
                {
                    if(dp[i-1][j]==first)
                    {
                        dp[i][j]=grid[i][j]+second;
                    }
                    else
                    {
                        dp[i][j]=grid[i][j]+first;
                    }
                }
                
                if(i==dp.size()-1)
                {
                    ans=min(ans,dp[i][j]);
                }
            }
        }  
        return ans;
        
    }
};