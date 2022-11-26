class Solution {
public:
    int explore(vector<vector<int>> &grid,int i,int j)
    {
        int ans=0;
        if(i<0 || j<0|| i>=grid.size() ||j>=grid[0].size() || grid[i][j]==0)
        {
            return 0;
        }
        int temp=grid[i][j];
        grid[i][j]=0;
        ans=max(ans,explore(grid,i-1,j));
        ans=max(ans,explore(grid,i+1,j));
        ans=max(ans,explore(grid,i,j+1));
        ans=max(ans,explore(grid,i,j-1));
        grid[i][j]=temp;
        return ans+grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]>0)
                {
                    ans=max(ans,explore(grid,i,j));
                    
                }
            }
        }
        return ans;
    }
};