class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool dirc=true;
        int m=mat.size();
        int n=mat[0].size();
        int i=0;
        int j=0;
        vector<int> ans;
        while(i>=0 && j>=0 && i<m && j<n)
        {
            if(dirc)
            { 
                while(i>0 && j<n-1)
                {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                ans.push_back(mat[i][j]);
                dirc=false;
                if(j==n-1)
                {
                    i++;
                }
                else
                {
                    j++;
                }
                
            }
            else
            {
                while(j>0 && i<m-1)
                {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                ans.push_back(mat[i][j]);
                dirc=true;
                if(i==m-1)
                {
                    j++;
                }
                else
                {
                    i++;
                }
            }
        }
        return ans;
    }
};