class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        map<int, int> mpp;
        int mn1 = *min_element(basket1.begin(), basket1.end());
        int mn2 = *min_element(basket2.begin(), basket2.end());
        int mn = min(mn1, mn2);

        for (int i = 0; i < n; i++) {
            mpp[basket1[i]]++;
            mpp[basket2[i]]++;
        }

        for (auto i : mpp)
            if (i.second & 1)
                return -1;
        long long cost = 0;

        map<int, int> mpp1;
        map<int, int> mpp2;
        for (int i = 0; i < n; i++) {
            mpp1[basket1[i]]++;
            mpp2[basket2[i]]++;
        }
        vector<int> v1, v2;
        for (auto i : mpp1) {
            int a = i.second;
            int b = 0;
            if (mpp2.find(i.first) != mpp2.end())
                b = mpp2[i.first];
            if (a <= b)
                continue;

            for (int j = 0; j < (abs(a - b) / 2); j++) {
                v1.push_back(i.first);
            }
        }
        for (auto i : mpp2) {
            int a = i.second;
            int b = 0;
            if (mpp1.find(i.first) != mpp1.end())
                b = mpp1[i.first];
            if (a <= b)
                continue;

            for (int j = 0; j < (abs(a - b) / 2); j++) {
                v2.push_back(i.first);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        n = v1.size();

        for (int i = 0; i < n; i++) {
            cost += min(2 * mn, min(v1[i], v2[n - i - 1]));
        }

        return cost;
    }
};