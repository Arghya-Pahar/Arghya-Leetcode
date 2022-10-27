class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> mp;
        vector<vector<int>> ans;
        for(int i=0;i<groupSizes.size();i++)
        {
            int s=groupSizes[i];
            if(mp.find(s)==mp.end())
            {
                vector<int> store;
                store.push_back(i);
                mp.insert({s,store});
            }
            else
            {
                mp[s].push_back(i);
            }
            if(mp[s].size()==s)
            {
                ans.push_back(mp[s]);
                mp[s]={};
            }
            
            
        }
        return ans;
    }
};