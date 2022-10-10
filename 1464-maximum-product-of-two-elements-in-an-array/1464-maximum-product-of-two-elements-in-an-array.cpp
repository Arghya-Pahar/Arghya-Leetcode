class Solution {
public:
    static bool comp(int a,int b)
    {
        return a<b;
    }
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        int a= nums[nums.size()-1]-1;
        int b=nums[nums.size()-2]-1;
        return a*b;
    }
};