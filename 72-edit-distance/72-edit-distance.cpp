class Solution {
public:
    int minDistance(string word1, string word2) {
        // if(word1.size()==0)
        // {
        //     return word2.size();
        // }
        // else if(word2.size()==0)
        // {
        //     return word1.size();
        // }
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=0;
                }
                else if(i==0)
                {
                    dp[i][j]=j;
                }
                else if(j==0)
                {
                    dp[i][j]=i;
                }
                else
                {
                    if(word1[i-1]==word2[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                        dp[i][j]=dp[i][j]+1;
                    }
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[dp.size()-1][dp[0].size()-1];
        
    }
};