class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int l=0,r=i-1;
            while(l<i)
            {
                dp[i]+=dp[l]*dp[r];
                l++;
                r--;
            }
            
        }
        return dp[n];
    }
};