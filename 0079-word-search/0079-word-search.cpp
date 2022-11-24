class Solution {
public:
    bool anss=false;
    void dfs(vector<vector<char>>& board,int i ,int j,int k,string str)
    {
        if(k==str.size())
        {
            anss=true;
            return;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='@' || board[i][j]!=str[k])
        {
            return;
        }
        char ori=board[i][j];
        board[i][j]='@';
        dfs(board,i+1,j,k+1,str);
        dfs(board,i-1,j,k+1,str);
        dfs(board,i,j+1,k+1,str);
        dfs(board,i,j-1,k+1,str);
        board[i][j]=ori;
        return;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    dfs(board,i,j,0,word);
                    
                }
            }
        }
        return anss;
    }
};