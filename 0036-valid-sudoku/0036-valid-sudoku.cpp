class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    string s1="row"+to_string(i)+to_string(board[i][j]);
                    string s2="col"+to_string(j)+to_string(board[i][j]);
                    string s3="box"+to_string((i/3)*3+j/3)+to_string(board[i][j]);
                    if(s.find(s1)!=s.end() || s.find(s2)!=s.end() || s.find(s3)!=s.end())
                    {
                        return false;
                    }
                    s.insert(s1);
                    s.insert(s2);
                    s.insert(s3);
                }
            }
        }
        return true;
    }
};