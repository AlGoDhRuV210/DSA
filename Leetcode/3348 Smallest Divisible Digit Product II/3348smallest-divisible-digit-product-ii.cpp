

class Solution {
public:
    long long getGcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    string smallestNumber(string num, long long t) {
        long long temp = t;
        for (int i = 2; i <= 9; i++) {
            while (temp % i == 0) {
                temp = temp / i;
            }
        }

        if (temp > 1) {
            return "-1";
        }

        int n = num.length();
        vector<long long> rem(n + 1);
        rem[0] = t;

        int pos = n - 1;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                pos = i;
                break;
            }
            long long d = num[i] - '0';
            rem[i + 1] = rem[i] / getGcd(rem[i], d);
        }

        if (rem[n] == 1) {
            return num;
        }

        for (int i = pos; i >= 0; i--) {
            while (num[i] < '9') {
                num[i]++;

                long long d = num[i] - '0';
                long long req = rem[i] / getGcd(rem[i], d);

                int k = 9;

                for (int j = n - 1; j > i; j--) {
                    while (req % k != 0) {
                        k--;
                    }
                    req = req / k;
                    num[j] = '0' + k;
                }

                if (req == 1) {
                    return num;
                }
            }
        }

        string ans = "";

        for (int i = 9; i >= 2; i--) {
            while (t % i == 0) {
                ans += to_string(i);
                t = t / i;
            }
        }

        int len = n + 1;
        while (ans.length() < len) {
            ans += "1";
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
