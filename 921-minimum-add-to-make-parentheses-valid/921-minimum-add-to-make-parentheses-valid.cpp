class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')' && st.size()==0)
            {
                st.push(')');
            }
            else if(s[i]=='(')
            {
                st.push('(');
            }
            else if(s[i]==')' && st.top()=='(')
            {
                st.pop();
            }
            else if(s[i]==')' && st.top()==')')
            {
                st.push(')');
            }
                
        }
        return st.size();
        
    }
};