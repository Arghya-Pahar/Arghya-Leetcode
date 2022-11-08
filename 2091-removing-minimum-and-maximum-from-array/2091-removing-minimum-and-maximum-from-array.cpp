class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX,maxi=INT_MIN,idx1=-1,idx2=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                idx1=i;
            }
            if(nums[i]<mini)
            {
                mini=nums[i];
                idx2=i;
            }
            
        }
        cout<<idx1<<" "<<idx2;
        if(idx2>idx1)
        {
            swap(idx1,idx2);
        }
        return min(idx1+1,min(n-idx2,idx2+1+n-idx1));
    }
};