class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            string cur = "";
            int ele = nums[i];

            for (int j = 25; j >= 0; j--) {
                if(ele==0) break;
                while (ele >= (1 << j))
                {
                    cur += ('a' + j);
                    ele -= (1 << j);
                }
            }
            ans[i] = cur;
        }
        return ans;
    }
};