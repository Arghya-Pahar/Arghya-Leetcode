class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans1;
        vector<int> ans2;
        if(changed.size()%2!=0)
        {
            return ans2;
        }
        sort(changed.begin(),changed.end());
        map<int,int> mp;
        for(int i=0;i<changed.size();i++)
        {
            mp[changed[i]]++;
        }
        for(int i=0;i<changed.size();i++)
        {
            if(mp[changed[i]]==0)
            {
                continue;
            }
            if(mp[2*changed[i]]==0)
            {
                return {};
            }
            if(mp[changed[i]]&&mp[changed[i]*2])
            {
                ans1.push_back(changed[i]);
                mp[changed[i]]--;
                mp[changed[i]*2]--;
            }
        }
    return ans1;
    }
};