class Solution {
public:
    long long numberOfWays(string s) {
        long long ones=0;
        long long zero=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
                zero++;
            else
                ones++;
        }
        long long ans=0;
        long long cur0=0;
        long long cur1=0;
        if(s[0]=='0')
            cur0++;
        else
            cur1++;
        for(int i=1;i<s.size()-1;i++)
        {
            if(s[i]=='0')
            {
                cur0++;
                ans+=cur1*(ones-cur1);
            }
            else
            {
                cur1++;
                ans+=cur0*(zero-cur0);
            }
        }
        return ans;
    }
};