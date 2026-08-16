class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; i++)
            stones[i] %= 3;

        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(auto i : stones)
        {
            if(i==0) cnt0++;
            else if(i==1) cnt1++;
            else cnt2++;
        }
        if(cnt0%2==0)
        {
            return cnt2>0 && cnt1>0;
        }
        return abs(cnt2-cnt1)>2;
    }
};