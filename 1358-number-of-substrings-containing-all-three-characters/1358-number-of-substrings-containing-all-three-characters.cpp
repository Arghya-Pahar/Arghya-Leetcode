class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int i=0,j=0;
        int ans=0;
        while(j<s.size())
        {
            mp[s[j]]++;
            while(mp['a']!=0 && mp['b']!=0 && mp['c']!=0)
            {
                ans+=s.size()-j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
        
    }
};