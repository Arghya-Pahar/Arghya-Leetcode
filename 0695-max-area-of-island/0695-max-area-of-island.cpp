class Solution {
public:
    int ans=0;
    int count(vector<vector<int>> &grid,int i,int j,int k)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
        {
            return k;
        }
        grid[i][j]=0;
        k++;
        k=count(grid,i+1,j,k);
        k=count(grid,i,j+1,k);
        k=count(grid,i-1,j,k);
        k=count(grid,i,j-1,k);
        return k;
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0 && grid[0].size()==0)
            return 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int c=count(grid,i,j,0);
                    ans=max(ans,c);
                }
            }
        }
        return ans;
    }
};