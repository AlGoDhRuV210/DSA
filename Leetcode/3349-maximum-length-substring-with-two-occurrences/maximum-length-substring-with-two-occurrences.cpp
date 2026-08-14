class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        string nums = s;
        unordered_map<char, int> mpp;
        int mxlen = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            char ele = nums[i];
            mpp[ele]++;
            if (mpp[ele] <= 2) {
                mxlen = max(i - j + 1, mxlen);
            } else {
                while (mpp[ele] > 2) {
                    mpp[nums[j]]--;
                    j++;
                }
            }
        }
        return mxlen;
    }
};