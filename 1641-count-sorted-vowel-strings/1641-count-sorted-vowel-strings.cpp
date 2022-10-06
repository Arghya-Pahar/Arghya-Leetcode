class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n,vector<int> (5,0));
        for(int i=dp.size()-1;i>=0;i--)
        {
            for(int j=dp[0].size()-1;j>=0;j--)
            {
                if(i==dp.size()-1)
                {
                    dp[i][j]=1;
                }
                else if(j==dp[0].size()-1)
                {
                    dp[i][j]=1;
                }
                else 
                {
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
                }
            }
        }
        int sum=0;
        for(int i=0;i<dp[0].size();i++)
        {
            sum=sum+dp[0][i];
        }
        return sum;
        
    }
};