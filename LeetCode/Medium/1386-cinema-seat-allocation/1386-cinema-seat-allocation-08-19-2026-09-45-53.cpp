class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long ans = 0;
        map<int, vector<int>> mpp;
        for (auto i : reservedSeats)
            mpp[i[0]].push_back(i[1]);
        int vis_rows = mpp.size();
        for (auto jj : mpp) {
            vector<int> v = jj.second;

            // sort(v.begin(), v.end());
            int p1 = 1, p2 = 1, p3 = 1;

            for (auto i : v) {
                if (i == 2 || i == 3 || i == 4 || i == 5) {
                    p1 = 0;
                    break;
                }
            }
            for (auto i : v) {
                if (i == 7 || i == 6 || i == 4 || i == 5) {
                    p2 = 0;
                    break;
                }
            }
            for (auto i : v) {
                if (i == 7 || i == 6 || i == 8 || i == 9) {
                    p3 = 0;
                    break;
                }
            }
            int cur;
            if (p1 == 1 && p3 == 1)
                cur = 2;
            else if (p2 == 1)
                cur = 1;
            else if(p1==1 || p3==1)
                cur = 1;
                else
                cur=0;
            ans += cur;
        }
        ans += (n - vis_rows) * 2;
        return ans;
    }
};