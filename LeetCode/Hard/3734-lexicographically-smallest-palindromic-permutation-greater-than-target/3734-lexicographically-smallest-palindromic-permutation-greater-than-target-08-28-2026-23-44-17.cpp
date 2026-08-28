class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size(), cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                odd++;
                mid = 'a' + i;
            }
            cnt[i] /= 2;
        }

        if (odd > 1) return "";

        int m = n / 2;
        string ans(n, ' ');
        int pos = 0;

        while (pos < m && cnt[target[pos] - 'a']) {
            ans[pos] = target[pos];
            cnt[target[pos] - 'a']--;
            pos++;
        }

        if (pos == m) {
            if (n & 1) ans[m] = mid;
            for (int i = 0; i < m; i++)
                ans[n - 1 - i] = ans[i];

            if (ans > target) return ans;
        }

        while (true) {
            if (pos < m) {
                for (int c = target[pos] - 'a' + 1; c < 26; c++) {
                    if (!cnt[c]) continue;

                    ans[pos] = 'a' + c;
                    cnt[c]--;

                    int j = pos + 1;

                    for (int x = 0; x < 26; x++) {
                        while (cnt[x]--) {
                            ans[j++] = 'a' + x;
                        }
                    }

                    if (n & 1) ans[m] = mid;
                    for (int i = 0; i < m; i++)
                        ans[n - 1 - i] = ans[i];

                    return ans;
                }
            }

            if (pos == 0) return "";

            pos--;
            cnt[target[pos] - 'a']++;
        }
    }
};