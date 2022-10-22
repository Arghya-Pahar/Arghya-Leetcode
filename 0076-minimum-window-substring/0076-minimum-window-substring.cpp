class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        map<char,int> mp2;
        for(int i=0;i<t.size();i++)
        {
            mp2[t[i]]++;
        }
        int i=0;
        int j=0;
        int mct=0;
        int dmct=t.size();
        map<char,int> mp1;
        while(i<s.size() && j<s.size())
        {
            if(mct<dmct)
            {
            mp1[s[j]]++;
            if(mp2.find(s[j])!=mp2.end())
            {
            if(mp1[s[j]]<=mp2[s[j]])
            {
                mct++;
                
            }
            }
                j++;
            }
            while(i<j && mct==dmct)
            {
                string str=s.substr(i,j-i);
                if(ans.size()==0 || str.size()<ans.size())
                {
                    ans=str;
                }
                if(mp1[s[i]]==1)
                {
                    mp1.erase(s[i]);
                }
                else
                {
                    mp1[s[i]]--;
                }
                if(mp2.find(s[i])!=mp2.end())
                {
                if(mp1[s[i]]<mp2[s[i]])
                {
                    mct--;
                }
                }
                i++;
            }
    
        }
        return ans;
    }
};