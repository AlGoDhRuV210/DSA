class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        for (auto i : nums)
            m[i] = 1;
        for (int i = 1; i <= n; i++)
            if (m[i] == 0)
                return i;
        return n+1;
    }
};