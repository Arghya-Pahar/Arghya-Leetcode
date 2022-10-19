class Solution {
public:
    vector<vector<int>> ans;
    void combisum(vector<int> &candidate,int target,int src,int sum,vector<int> &storee)
    {
        if(src==candidate.size())
        {
             if(target==sum)
             {
                 ans.push_back(storee);
             }
            return;
        }
        else
        {
            if(candidate[src]<=target-sum)
            {
            storee.push_back(candidate[src]);
            combisum(candidate,target,src,sum+candidate[src],storee);
            storee.pop_back();
            }
            
            combisum(candidate,target,src+1,sum,storee);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> store;
        combisum(candidates,target,0,0,store);
        return ans;
        
    }
};