class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> arr(10001,0);
        for(int i=0;i<nums.size();i++)
        {
            arr[nums[i]]++;
        }
        int inc=0;
        int exc=0;
        for(int i=1;i<arr.size();i++)
        {
            int new_inc=arr[i]*i+exc;
            int new_exc=max(inc,exc);
            inc=new_inc;
            exc=new_exc;
        }
        return max(inc,exc);
    }
};