class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int ans = 0;
        for (auto i : s) {
            if (i == '1')
                ans++;
        }
        int left = 0;
        int right = 0;
        int i = 0;
        while (i < n && s[i] == '0') {
            i++;
            left++;
        }
        int mx = 0;
        for (; i < s.length(); i++) {
            while (i < n && s[i] == '1')
                i++;

            while (i < n && s[i] == '0') {
                i++;
                right++;
            }
            if (right == 0)
                continue;
            if (left == 0) {
                left = right;
                right = 0 ;
                continue;
            }

            mx = max(mx, right + left);
            left = right;
            right = 0;
        }
        return ans + mx;
    }
};