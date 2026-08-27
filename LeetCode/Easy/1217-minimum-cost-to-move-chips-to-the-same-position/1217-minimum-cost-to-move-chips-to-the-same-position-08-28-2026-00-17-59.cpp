class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int ans = 0;
        int odd = 0, even = 0;
        for (auto i : position) {

            if (i & 1)
                odd++;
            else
                even++;
        }

        if(odd>even)
        return even;
        else return odd;
    }
};