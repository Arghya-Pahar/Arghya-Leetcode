class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            int low=i+1;
            int high=nums.size()-1;
            while(low<high)
            {
                int sum=nums[i]+nums[low]+nums[high];
                if(diff>abs(target-sum))
                {
                    diff=abs(target-sum);
                    ans=sum;
                }
                if(sum==target)
                    return target;
                else if(sum>target)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        return ans;
    }
};