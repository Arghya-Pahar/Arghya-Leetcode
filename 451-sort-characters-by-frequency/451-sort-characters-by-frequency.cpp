class Solution {
public:
    bool static comp(pair<char,int> &a,pair<char,int> &b)
    {
        return a.second>b.second;
    }
    string frequencySort(string s) {
        map<char,int> mp;
        vector<pair<char,int>> v;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            v.push_back({it->first,it->second});
        }
        sort(v.begin(),v.end(),comp);
        string ans="";
        for(int i=0;i<v.size();i++)
        {
            int n=v[i].second;
            while(n--)
            {
                ans+=v[i].first;
            }
        }
        return ans;
        
    }
};