class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> ans(m);
        for(int j=0;j<m;j++)
        {
            int cpos=j;
            int npos=-1;
            for(int i=0;i<n;i++)
            {
                npos=cpos+grid[i][cpos];
                if(npos<0 || npos>=m || grid[i][cpos]!=grid[i][npos])
                {
                    cpos=-1;
                    break;
                }
                cpos=npos;

            }
            ans[j]=cpos;

        }
        return ans;
    }
};