class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count=0;
        for(int i=matrix.size()-1;i>=0;i--)
        {
            for(int j=matrix[0].size()-1;j>=0;j--)
            {
                if(i!=matrix.size()-1 && j!=matrix[0].size()-1 && matrix[i][j]!=0)
                {
                    matrix[i][j]+=min(matrix[i+1][j],min(matrix[i+1][j+1],matrix[i][j+1]));
                }
                count+=matrix[i][j];
            }
        }
        return count;
    }
};