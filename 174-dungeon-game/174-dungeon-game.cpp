class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(),vector<int> (dungeon[0].size(),0));
        for(int i=dp.size()-1;i>=0;i--)
        {
            for(int j=dp[0].size()-1;j>=0;j--)
            {
                if(i==dp.size()-1 && j==dp[0].size()-1)
                {
                    dp[i][j]=max(1-dungeon[i][j],1);
                    
                }
                else if(i==dp.size()-1)
                {
                    dp[i][j]=max(dp[i][j+1]-dungeon[i][j],1);
                }
                else if(j==dp[0].size()-1)
                {
                    dp[i][j]=max(dp[i+1][j]-dungeon[i][j],1);
                }
                else
                {
                    int down=max(dp[i+1][j]-dungeon[i][j],1);
                    int right=max(dp[i][j+1]-dungeon[i][j],1);
                    dp[i][j]=min(down,right);
                    
                    
                }
            }
        }
        return dp[0][0];
    }
};