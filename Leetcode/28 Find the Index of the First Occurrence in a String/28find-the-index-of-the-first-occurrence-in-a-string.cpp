class Solution {
public:
    vector<int> solve(const string& s) {
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

    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size(); // smaller
        int i = 0, j = 0;
        string z;
        z = needle + "&" + haystack;
        vector<int> ans;
        vector<int> x = solve(z);
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == n)
               return(i - n - 1);
        }
        return -1;
    }
};