// LeetCode 2958 - Length of Longest Subarray With at Most K Frequency
// Difficulty: Medium
// Topic: Sliding Window, Hash Map
// Time: O(n) average
// Space: O(n)

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int mxlen = 0;
        int j = 0;

        for(int i = 0; i < n; i++) {
            int ele = nums[i];
            mpp[ele]++;

            if(mpp[ele] <= k) {
                mxlen = max(i - j + 1, mxlen);
            }
            else {
                while(mpp[ele] > k) {
                    mpp[nums[j]]--;
                    j++;
                }
            }
        }

        return mxlen;
    }
};