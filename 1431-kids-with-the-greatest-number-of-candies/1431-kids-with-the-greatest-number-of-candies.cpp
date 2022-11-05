class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int maxi=INT_MIN;
        for(int i=0;i<candies.size();i++)
        {
            maxi=max(maxi,candies[i]);
        }
        vector<bool> ans(candies.size());
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extra>=maxi)
            {
                ans[i]=true;
            }
            else
            {
                false;
            }
        }
        return ans;
    }
};