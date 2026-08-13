class Solution
{
public:
    bool helper(vector<vector<char>> &board, string word,  int index, pair<int, int> p,  vector<vector<int>> &vis, int m, int n)
    {
        if (index == word.size())
        {
                return true;
        }
        char c = word[index];
        int i = p.first;
        int j = p.second;
        if (i + 1 < m)
        {
            if (board[i + 1][j] == c &&  !vis[i+1][j] )
            {
                  vis[i+1][j] = 1;
                if (helper(board, word, index + 1, {i + 1, j}, vis, m, n))
                    return true;
                 vis[i+1][j] = 0;
            }
        }
        if (i - 1 >= 0)
        {
            if (board[i - 1][j] == c &&  !vis[i-1][j])
            {
                vis[i-1][j] = 1;
                if (helper(board, word,  index + 1, {i - 1, j}, vis, m, n))
                    return true;
                 vis[i-1][j] = 0;
            }
        }
        if (j - 1 >= 0)
        {
            if (board[i][j-1] == c &&  !vis[i][j-1])
            {
                  vis[i][j-1] = 1;
                if (helper(board, word,  index + 1, {i ,j-1}, vis, m, n))
                    return true;
                 vis[i][j-1] = 0;
            }
        }
        if (j + 1 < n)
        {
            if (board[i][j+1] == c &&  !vis[i][j+1])
            {
                vis[i][j+1] = 1;
                if (helper(board, word,  index + 1, {i , j+1}, vis, m, n))
                    return true;
                vis[i][j+1] = 0;
            }
        }
        return false;

    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        // set<pair<int, int>> s;
         vector<vector<int>> vis(m, vector<int>(n,0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                   vis[i][j] = 1;
                    if (helper(board, word,1, {i, j}, vis, m, n))
                        return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;

        // return helper(board, word, "", 0,{0,0},s);
    }
};