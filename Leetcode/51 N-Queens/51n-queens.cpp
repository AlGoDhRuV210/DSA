class Solution
{
public:
    // bool issafe(int col, int row, int n, vector<string> cur)
    // {
    //     // check above
    //     int r = row, c = col;
    //     while (row > 0)
    //     {
    //         if (cur[row][col] == 'Q')
    //             return false;
    //         row--;
    //     }
    //     row = r;
    //     // right diagonal
    //     while (row > 0 && col <= n)
    //     {
    //         if (cur[row][col] == 'Q')
    //             return false;
    //         row--;
    //         col++;
    //     }
    //     row = r;
    //     col = c;
    //     // left diagonal
    //     while (row > 0 && col > 0)
    //     {
    //         if (cur[row][col] == 'Q')
    //             return false;
    //         row--;
    //         col--;
    //     }
    //     return true;
    // }
    void helper(int n, vector<vector<string>> &ans, vector<string> cur, int row,  vector<int> above,  vector<int> v,  vector<int> left)
    {
        if (row == n)
        {
            ans.push_back(cur);
            return;
        }
        // check each column
        for (int i = 0; i < n; i++)
        {
            if (above[i]==0 && v[row+i]==0 && left[n-1+i-row]==0)
            {
                cur[row][i] = 'Q';
                above[i]=1;
                v[row+i]=1;
                left[n-1+i-row]=1;
                helper(n, ans, cur, row + 1,above,v,left);
                left[n-1+i-row]=0;
                v[row+i]=0;
                above[i]=0;
                cur[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int>;
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> cur(n,s);
          vector<int> v(2*n+1,0);
          vector<int> above(n,0);
          vector<int> left(2*n-1,0);
        // for (auto i : cur)
        //     i = s;
        helper(n, ans, cur, 0,above,v,left);
        return ans;
    }
};