class Solution {
public:
    vector<int> getRow(int row) {
        vector<vector<int>> dp(row+1,vector<int> (row+1,0));
        vector<int> ans;
        for(int i=0;i<dp.size();i++)
        {
            vector<int> store;
            for(int j=0;j<=i;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=1;
                }
                else if(j==0 || j==i)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }
                store.push_back(dp[i][j]);
            }
            ans=store;
        }
        return ans;
        
    }
};