class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> st;
        map<char,int> st1;
        for(int i=0;i<s.size();i++)
        {
            st[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            st1[t[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(st.find(t[i])==st.end() || st1[t[i]]>st[t[i]])
            {
                return t[i];
            }
        }
        
        return 'a';
    }
};