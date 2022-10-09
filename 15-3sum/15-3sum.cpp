class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            int a=nums[i];
            int t=-a;
            int low=i+1;
            int high=nums.size()-1;
            while(low<high)
            {
                if(nums[low]+nums[high]==t)
                {
                    ans.push_back({nums[i],nums[low],nums[high]});
                    while(low<high && nums[low]==nums[low+1])
                    {
                        low++;
                    }
                    while(low<high && nums[high]==nums[high-1])
                    {
                        high--;
                    }
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]>t)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
            while(i+1<nums.size() && nums[i]==nums[i+1])
            {
                i++;
            }
        }
        return ans;
    }
};