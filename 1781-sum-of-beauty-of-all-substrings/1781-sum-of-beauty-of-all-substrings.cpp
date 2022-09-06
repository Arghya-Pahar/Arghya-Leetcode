class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            map<char,int> mp;
            
            for(int j=i;j<s.size();j++)
            {
                int maxi=INT_MIN;
                int mini=INT_MAX;
                mp[s[j]]++;
                for(auto it=mp.begin();it!=mp.end();it++)
                {
                    mini=min(mini,it->second);
                    maxi=max(maxi,it->second);
                }
                sum+=maxi-mini;
            
            }
            
        }
        return sum;
        
    }
};