class Solution {
public:
    bool palindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    string to_binary(int n) {
        string s = "";

        for (int i = 7; i >= 0; i--) {
            s += ((n >> i) & 1) + '0';
        }
        return s;
    }
    bool isPalindromic(string s) {

        string ans = "";
        for (auto i : s) {
            ans += to_binary(i);
        }
        return palindrome(ans);
    }
};