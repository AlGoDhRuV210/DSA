class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int ans = 0;
        int bal = 0;
        for (auto i : s) {
            if (i == '(')
                bal++;
            else
                bal--;
            if (bal < 0) {
                ans++;
                bal = 0;
            }
        }
        if (bal != 0)
            ans += abs(bal);
        return ans;
    }
};