class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            ans.push_back(s[i]);
            if(ans.size()>=part.size() && ans.substr(ans.size()-part.size())==part)
            {
                int count=part.size();
                while(count--)
                {
                    ans.pop_back();
                }
            }
        }
        return ans;
        
    }
};