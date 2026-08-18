class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = i; (i + k - 1 < n && j <= i + k - 1 && j < n); j++) {
                if (s.find(nums[j]) == s.end())
                    mpp[nums[j]]++;
                s.insert(nums[j]);
            }
        }
        int ans = -1;
        for (auto i : mpp) {
            if (i.second == 1)
                ans = max(ans, i.first);
        }
        return ans;
    }
};