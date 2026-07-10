class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();

        if (image[sr][sc] == color)
            return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int initial = image[sr][sc];
        image[sr][sc] = color;
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            int row[] = {-1, 0, 1, 0};
            int col[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int nrow = i + row[k];
                int ncol = j + col[k];
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) {
                    if (image[nrow][ncol] == initial) {
                        image[nrow][ncol] = color;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return image;
    }
};