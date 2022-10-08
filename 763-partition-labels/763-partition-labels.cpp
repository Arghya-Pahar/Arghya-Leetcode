class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mp;
        vector<int> ans;
        int maxi=-1,j=-1;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]=i;
        }
        for(int i=0;i<s.size();i++)
        {
            maxi=max(maxi,mp[s[i]]);
            if(maxi==i)
            {
                ans.push_back(i-j);
                j=i;
            }
        }
        return ans;
    }
};