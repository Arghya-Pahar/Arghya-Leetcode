class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans=0;
        int index=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                if(st.top()!=-1 && s[st.top()]=='(')
                {
                    st.pop();
                    ans=max(ans,i-st.top());
                    
                }
                else
                {
                    st.push(i);
                }
            }
            else
            {
                st.push(i);
            }
            
        }
        return ans;
        
    }
};