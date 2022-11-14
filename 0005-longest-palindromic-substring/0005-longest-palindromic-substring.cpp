class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        int b,l;
        for(int g=0;g<n;g++)
        {
            for(int j=g,i=0;j<n;j++,i++)
            {
                if(g==0)
                {
                    dp[i][j]=1;
                    b=i;
                    l=g;
                }
                else if(g==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=1;
                        b=i;
                        l=g;
                    }
                }
                else
                {
                    if(s[i]==s[j]&& dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                        b=i;
                        l=g;
                    }
                }
            }
        }
        cout<<l;
        string str=s.substr(b,l+1);
        return str;
        
        
    }
};