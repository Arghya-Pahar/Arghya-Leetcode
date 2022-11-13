class Solution {
public:
    int binarysearch(vector<int> &nums,int tar)
    {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==tar)
            {
                return mid;
            }
            else if(nums[mid]>tar)
            {
                high=mid-1;
            }
            else if(nums[mid]<tar)
            {
                low=mid+1;
            }
            
        }
        return low;
    }
    int searchInsert(vector<int>& nums, int target) {
        int ans=binarysearch(nums,target);
        return ans;
        
        
    }
};