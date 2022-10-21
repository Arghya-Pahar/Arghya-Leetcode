class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]--;
        }
        int count=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            count+=abs(it->second);
        }
        return count;
        
        
    }
};