class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int mnlen = n + 1;
        if(k==1)
        {
            for(auto i : s)
            {
                if(i=='1')
                return "1";
            }
            return "";
        }

        for (int i = 0; i < n; i++) {
            int cur = s[i] == '1';

            for (int j = i + 1; j < n; j++) {
                if (s[j] == '1')
                    cur++;
                if (cur == k) {
                    mnlen = min(mnlen, j - i + 1);
                    break;
                }
            }
            if (cur == k) {
                mnlen = min(mnlen, n - i + 1);
            }
        }

        if (mnlen == n + 1)
            return "";
        string ans = "";
        for (int i = 0; i < n; i++) {
            int cur = s[i] == '1';
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '1')
                    cur++;
                if (cur == k && j - i + 1 == mnlen) {
                    string t = s.substr(i, mnlen);
                    if (ans == "" || t < ans)
                        ans = t;
                }
            }
        }
        return ans;
    }
};