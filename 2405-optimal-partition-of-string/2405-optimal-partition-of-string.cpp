class Solution {
public:
    int partitionString(string s) {
        map<char,int> mp;
        int count=0;
        int i=0;
        while(i<s.size())
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]++;
            }
            else
            {
                count++;
                mp.clear();
                mp[s[i]]++;
            }
            i++;
        }
        return count+1;
        
    }
};