class Solution {
public:
    vector<vector<int>> ans;
    void permu(vector<int> nums,vector<int> store)
    {
        if(nums.size()==0)
        {
            ans.push_back(store);
            return;
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                int n=nums[i];
                store.push_back(nums[i]);
                vector<int> splce;
                splce=nums;
                splce.erase(splce.begin()+i);
                permu(splce,store);
                store.pop_back();
            }
            
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> store;
        permu(nums,store);
        return ans;
        
    }
};