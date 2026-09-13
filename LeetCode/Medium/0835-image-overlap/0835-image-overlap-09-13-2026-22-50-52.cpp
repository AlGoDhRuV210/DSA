
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();
        map<pair<int, int>, int> mpp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int p = 0; p < n; p++) {
                    for (int q = 0; q < n; q++) {
                        if (img2[p][q] == 0 || img1[i][j] == 0)
                            continue;

                        int dx = p - i;
                        int dy = q - j;
                        mpp[{dx, dy}]++;
                    }
                }
            }
        }
        for (auto i : mpp)
            ans = max(ans, i.second);
        return ans;
    }
};