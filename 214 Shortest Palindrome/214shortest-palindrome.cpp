class Solution {
public:
    vector<int> solve(string& s) {
        int n = s.length();
        vector<int> z(n, 0);
        int left = 0, right = 0;

        for (int i = 1; i < n; i++) {
            if (i <= right)
                z[i] = min(right - i + 1, z[i - left]);

            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;

            if (i + z[i] - 1 > right) {
                left = i;
                right = i + z[i] - 1;
            }
        }

        return z;
    }
    string shortestPalindrome(string s) {
        if (s == "")
            return s;
        int n = s.length();
        vector<int> z;
        string temp = s;
        reverse(temp.begin(), temp.end());
        string k = s + "&" + temp;
        z = solve(k);

        int ans = 1;
        for (int i = n + 1; i < z.size(); i++) {
            if (i + z[i] == z.size()) {

                ans = max(ans, z[i]);
            }
        }
        string g = s.substr(ans, n - ans);
        reverse(g.begin(), g.end());
        return g + s;
    }
};