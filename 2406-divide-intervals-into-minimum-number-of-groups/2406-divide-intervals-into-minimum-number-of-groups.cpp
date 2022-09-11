class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> start(n);
        vector<int> dep(n);
        for(int i=0;i<n;i++)
        {
            start[i]=intervals[i][0];
            dep[i]=intervals[i][1];
        }
        sort(start.begin(),start.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0,count=0,ans=0;
        while(i<n && j<n)
        {
            if(start[i]<=dep[j])
            {
                i++;
                count++;
                
            }
            else
            {
                j++;
                count--;
            }
            
            ans=max(ans,count);
        }
        return ans;
    }
};