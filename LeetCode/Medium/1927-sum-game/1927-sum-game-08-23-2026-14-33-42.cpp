class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int l = 0, r = 0;
    
        int lm = 0, rm = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                lm++;
            else
                l += (num[i] - '0');
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rm++;
            else
                r += (num[i] - '0');
        }
        int mn = min(lm, rm);
        lm -= mn;
        rm -= mn;
        if (lm == 0 && rm == 0)
            return l != r;

        if (lm > 0) {
            if (l >= r)
                return true;
            int bobchance = lm / 2;
            int alicechance = lm - bobchance;
            if (9 * alicechance > abs(l - r))
                return true;

            if ((int)(ceil(abs(l - r) / 9.0)) > bobchance)
                return true;

            return false;
        }

        if (l <= r)
            return true;
        int bobchance = rm / 2;
        int alicechance = rm - bobchance;
        if (9 * alicechance > abs(l - r))
            return true;

        if ((int)(ceil(abs(l - r) / 9.0)) > bobchance)
            return true;

        return false;
    }
};