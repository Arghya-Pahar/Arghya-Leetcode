class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int i=0;
        string str1=strs[0];
        string str2=strs[strs.size()-1];
        while(i<str1.size()&& i<str2.size())
        {
            if(str1[i]==str2[i])
            {
                i++;
            }
            else
            {
                break;
            }
        }
        string ans=str1.substr(0,i);
        return ans;
    }
};