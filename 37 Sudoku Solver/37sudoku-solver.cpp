class Solution
{
public:
bool issafe(vector<vector<char>> &board,int i , int j , int k )
{
    for (int m = 0; m < 9; m++)
    {
        if(board[i][m]=='1'+k) return false;
        if(board[m][j]=='1'+k) return false;
        
        if(board[3*(i/3) + m/3][3*(j/3) + m%3] == '1'+k) return false;
    }
    
    return true;
}
    bool helper(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int k = 0; k < 9; k++)
                    {
                        if (issafe(board, i, j, k))
                        {
                            board[i][j] = '1' + k;
                            if (helper(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int k = 0; k < 9; k++)
                    {
                         if (issafe(board, i, j, k))

                      {  board[i][j] = '1' + k;
                        if (helper(board))
                            return true;
                        board[i][j] = '.';}
                    }
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        // m=n=9. {0,1,,,,,,,,,7,8}
        solve(board);
    }
};
