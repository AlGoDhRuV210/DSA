class Solution {
public:
    int digits(int n) {
        int a = 0;
        while (n > 0) {
            a++;
            n /= 10;
        }
        return a;
    }
    int countCommas(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int d = digits(i);
            if (d % 3 == 0)
                ans += (d / 3) - 1;
            else
                ans += (d / 3);
        }
        return ans;
    }
};