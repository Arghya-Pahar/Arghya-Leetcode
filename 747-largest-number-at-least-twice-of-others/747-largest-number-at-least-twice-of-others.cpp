class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=INT_MIN,idx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=maxi)
            {
                maxi=nums[i];
                idx=i;
            }
        }
        cout<<maxi;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=maxi)
            {
                if(2*nums[i]>maxi)
                {
                    return -1;
                }
            }
        }
        return idx;
    }
};