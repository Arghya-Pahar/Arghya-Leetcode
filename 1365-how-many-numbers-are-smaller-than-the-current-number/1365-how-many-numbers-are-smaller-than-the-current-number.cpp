class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> copy;
        copy=nums;
        map<int,int> mp;
        sort(copy.begin(),copy.end());
        for(int i=copy.size()-1;i>=0;i--)
        {
            mp[copy[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(mp[nums[i]]);
        }
        return ans;
    }
};