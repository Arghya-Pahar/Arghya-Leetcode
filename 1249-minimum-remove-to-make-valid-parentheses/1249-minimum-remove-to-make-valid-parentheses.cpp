class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.size()==0)
                {
                    s[i]='#';
                }
                else
                {
                    st.pop();
                }
            }
        }
        while(st.size()!=0)
        {
            s[st.top()]='#';
            st.pop();
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='#')
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};