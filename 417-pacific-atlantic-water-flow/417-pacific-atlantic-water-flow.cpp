class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans(heights.size(),vector<int> (heights[0].size(),0));
        for(int i=0;i<heights.size();i++)
        {
            pacific(heights,i,0,ans);
        }
        for(int i=0;i<heights[0].size();i++)
        {
            pacific(heights,0,i,ans);
        }
        for(int i=0;i<heights.size();i++)
        {
            atlantic(heights,i,heights[0].size()-1,ans);
        }
        for(int i=0;i<heights[0].size();i++)
        {
            atlantic(heights,heights.size()-1,i,ans);
        }
        return result;
    }
    void pacific(vector<vector<int>> &heights,int i,int j,vector<vector<int>> &ans)
    {
        if(i<0 || j<0 ||i>=heights.size()||j>=heights[0].size())
        {
            return;
        }
        if(ans[i][j]==1)
        {
            return;
        }
        ans[i][j]++;
        if(i+1>=0 && j>=0 && i+1<heights.size() && j<heights[0].size() && heights[i+1][j]>=heights[i][j])
        {
            pacific(heights,i+1,j,ans);
        }
        if(i>=0 && j+1>=0 && i<heights.size() && j+1<heights[0].size() && heights[i][j+1]>=heights[i][j])
        {
            pacific(heights,i,j+1,ans);
        }
        if(i-1>=0 && j>=0 && i-1<heights.size() && j<heights[0].size() && heights[i-1][j]>=heights[i][j])
        {
            pacific(heights,i-1,j,ans);
        }
        if(i>=0 && j-1>=0 && i<heights.size() && j-1<heights[0].size() && heights[i][j-1]>=heights[i][j])
        {
            pacific(heights,i,j-1,ans);
        }
    }
     void atlantic(vector<vector<int>> &heights,int i,int j,vector<vector<int>> &ans)
    {
        if(i<0 || j<0 ||i>=heights.size()||j>=heights[0].size())
        {
            return;
        }
        if(ans[i][j]==2 || ans[i][j]==3)
        {
            return;
        }
        ans[i][j]+=2;
         if(ans[i][j]==3)
        {
            vector<int> store(2);
            store[0]=i;
            store[1]=j;
            result.push_back(store);
        }
        if(i+1>=0 && j>=0 && i+1<heights.size() && j<heights[0].size() && heights[i+1][j]>=heights[i][j])
        {
            atlantic(heights,i+1,j,ans);
        }
        if(i>=0 && j+1>=0 && i<heights.size() && j+1<heights[0].size() && heights[i][j+1]>=heights[i][j])
        {
            atlantic(heights,i,j+1,ans);
        }
        if(i-1>=0 && j>=0 && i-1<heights.size() && j<heights[0].size() && heights[i-1][j]>=heights[i][j])
        {
            atlantic(heights,i-1,j,ans);
        }
        if(i>=0 && j-1>=0 && i<heights.size() && j-1<heights[0].size() && heights[i][j-1]>=heights[i][j])
        {
            atlantic(heights,i,j-1,ans);
        }
    }
    
};