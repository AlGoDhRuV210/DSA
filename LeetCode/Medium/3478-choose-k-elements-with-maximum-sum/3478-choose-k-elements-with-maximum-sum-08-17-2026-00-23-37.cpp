class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {
        int n = nums1.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<long long> ans(n, 0);
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums1[i], nums2[i]});
        sort(v.begin(), v.end());
        int f = 0;
        // int mn = -1;
        long long sum = v[0].second;
        pq.push(v[0].second);
        f++;
        if (n >= 2 && v[1].first > v[0].first) {
            ans[1] = sum;
        }
        for (int i = 1; i < n; i++) {
            int ele = v[i].second;
            pq.push(ele);
            if (f < k) {
                sum += ele;
                f++;
            } else {
                if (pq.top() == ele) {
                    pq.pop();
                } else {
                    sum += ele;
                    sum -= pq.top();
                    pq.pop();
                }
            }
            // if ( v[i].first == v[i - 1].first && i < n - 1)
            //     ans[i + 1] = ans[i];
            // else {
            //     if (i < n - 1)
            //         ans[i + 1] = sum;
            // }
            if (i < n - 1 && v[i].first == v[i + 1].first)
                ans[i + 1] = ans[i];
            else if (i < n - 1)
                ans[i + 1] = sum;
        }
        vector<int> final(n);
       map<int, long long> mpp;
        for (int i = 0; i < n; i++) {
            mpp[v[i].first] = ans[i];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = mpp[nums1[i]];
        }

        return ans;
    }
};