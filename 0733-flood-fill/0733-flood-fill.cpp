class Solution {
public:
void explore(vector<vector<int>>&image,int i,int j,int c,int k)
{
    if(i<0 && j<0 ||i>=image.size() || j>=image[0].size() || image[i][j]!=k)
    {
        return;
    }
    image[i][j]=c;
    explore(image,i+1,j,c,k);
    explore(image,i-1,j,c,k);
    explore(image,i,j+1,c,k);
    explore(image,i,j-1,c,k);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    
        int k=image[sr][sc];
        if(k==color)
            return image;
        explore(image,sr,sc,color,k);
        return image;
    }
};