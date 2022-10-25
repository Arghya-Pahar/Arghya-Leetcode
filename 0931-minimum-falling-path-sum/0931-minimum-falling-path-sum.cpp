class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),0));
        int ans=INT_MAX;
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0)
                {
                    dp[i][j]=matrix[i][j];
                }
                else if(j==0)
                {
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+matrix[i][j];
                }
                else if(j==dp[0].size()-1)
                {
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+matrix[i][j];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+matrix[i][j];
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