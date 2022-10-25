class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        int maxi=INT_MIN;
        for(int i=0;i<=n;i++)
        {
            if(i%2==0)
            {
                dp[i]=dp[i/2];
            }
            else
            {
                dp[i]=dp[i/2]+dp[(i+1)/2];
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};