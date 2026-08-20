class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans1;
        vector<int> ans2;
        int n = nums.size();
        ans1.push_back(nums[0]);
        ans2.push_back(nums[1]);
        for (int i = 2; i < n; i++) {
            if (ans1.back() > ans2.back())
                ans1.push_back(nums[i]);
            else
                ans2.push_back(nums[i]);
        }
        nums.assign(1,0);
        nums.pop_back();
        for (auto i : ans1)
            nums.push_back(i);
        for (auto i : ans2)
            nums.push_back(i);
        return nums;
    }
};