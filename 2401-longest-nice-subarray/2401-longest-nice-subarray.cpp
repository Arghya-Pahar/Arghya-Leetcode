class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int num=0;
        int i=0;
        int j=0;
        int ans=1;
        while(i<nums.size()&& j<nums.size())
        {
            while((num & nums[i])!=0)
            {
                num=num^nums[j];
                j++;
            }
            num=num|nums[i];
            ans=max(ans,i-j+1);
            i++;
            
        }
        return ans;
    }
};