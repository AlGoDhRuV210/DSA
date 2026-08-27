class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        sort(s.begin(), s.end());
        for (int i = n - 1; i >= 0; i--) {
            string prefix = target.substr(0, i);
            vector<int> freq(26, 0);
            for (char c : s)
                freq[c - 'a']++;

            bool possible = true;

            for (char c : prefix) {
                if (freq[c - 'a'] == 0) {
                    possible = false;
                    break;
                }
                freq[c - 'a']--;
            }

            if (!possible)
                continue;
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (freq[c] == 0)
                    continue;

                string ans = prefix;

                ans += char('a' + c);
                freq[c]--;
                for (int x = 0; x < 26; x++) {
                    while (freq[x] > 0) {
                        ans += char('a' + x);
                        freq[x]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};