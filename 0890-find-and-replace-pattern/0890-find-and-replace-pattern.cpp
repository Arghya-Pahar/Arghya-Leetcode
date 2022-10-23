class Solution {
public:
    bool func(string s1,string s2)
    {
        map<char,int> mp1;
        map<char,int> mp2;
        if(s1.size()!=s2.size())
            return false;
        else
        {
            for(int i=0;i<s1.size();i++)
            {
                if(mp1[s1[i]]!=mp2[s2[i]])
                {
                    return false;
                }
                mp1[s1[i]]=i+1;
                mp2[s2[i]]=i+1;
                    
            }
            
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            if(func(words[i],pattern))
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};