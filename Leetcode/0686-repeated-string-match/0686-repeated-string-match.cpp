class Solution {
public:
    int BASE = 1000000;
    int solve(string a, string target) {

        int m = a.size();
        int n = target.size();
        int targethash = 0;
        int power = 1;
        for (int i = 0; i < n; i++) {
            power = (power * 31) % BASE;
        }
        for (int i = 0; i < n; i++) {
            targethash = ((targethash * 31) + (target[i] - 'a' + 1)) % BASE;
        }
        int hash = 0;
        for (int i = 0; i < m; i++) {
            hash = ((hash * 31) + a[i] - 'a' + 1) % BASE;
            if (i >= n) {
                hash = (hash - (a[i - n] - 'a' + 1) * power) % BASE;
                if (hash < 0)
                    hash += BASE;
            }
            if (i >= n - 1) {
                if (hash == targethash) {
                    if (a.substr(i - n + 1, n) == target)
                        return i - n + 1;
                }
            }
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        if (a == b)
            return 1;
        string temp = a;
        int m = a.size();
        int n = b.size();
        int cnt = 1;
        // find b in a
        while (a.size() < b.size()) {
            a = a + temp;
            cnt++;
        }
        if (a == b)
            return cnt;
        if (solve(a, b) != -1)
            return cnt;
        if (solve(a + temp, b) != -1)
            return cnt + 1;

        return -1;
    }
};