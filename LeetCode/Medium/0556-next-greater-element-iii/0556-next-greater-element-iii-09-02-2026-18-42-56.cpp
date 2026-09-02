class Solution {
public:
    int nextGreaterElement(int nn) {
        int ans = INT_MAX;

        string s = to_string(nn);

        int n = s.size();
        int i = n - 1;
        while (i > 0) {
            if (s[i] > s[i - 1]) {
                int j = i;
                int minindex = i;
                int ele = s[i] - '0';
                while (j < n) {
                    if (s[j] > s[i - 1] && s[j]-'0' < ele) {
                        minindex = j;
                        ele = s[j];
                    }

                    j++;
                }
                swap(s[i - 1], s[minindex]);
                sort(s.begin() + i, s.end());
                long long x = stoll(s);
                return x > INT_MAX ? -1 : x;
            }
            i--;
        }
        return -1;
    }
};