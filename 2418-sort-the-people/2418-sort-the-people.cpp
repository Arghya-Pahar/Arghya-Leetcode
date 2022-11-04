class Solution {
public:
    static bool comp(int &a,int &b)
    {
        return a>b;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> mp;
        vector<string> ans;
        for(int i=0;i<names.size();i++)
        {
            mp.insert({heights[i],names[i]});
        }
        sort(heights.begin(),heights.end(),comp);
        for(int i=0;i<heights.size();i++)
        {
           
            ans.push_back(mp[heights[i]]);
        }
        return ans;
    }
};