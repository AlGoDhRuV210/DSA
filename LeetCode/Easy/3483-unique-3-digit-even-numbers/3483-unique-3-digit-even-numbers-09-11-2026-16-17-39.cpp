class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<string> s;
        int n = digits.size();
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;

                for (int k = 0; k < n; k++) {
                    if (k == j || k == i)
                        continue;
                    string cur = to_string(digits[i]) + to_string(digits[j]) +
                                 to_string(digits[k]);

                    if (cur[0] != '0' && ((cur[2] - '0') % 2 == 0))
                        s.insert(cur);
                }
            }
        }
        return s.size();
    }
};