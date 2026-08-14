class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        map<int, int> mpp;
        for (auto i : hand)
            mpp[i]++;
        for (auto i : mpp)
            pq.push({i.first, i.second});
        while (!pq.empty()) {
            if (pq.size() < groupSize)
                return false;
            int temp = groupSize;
            vector<pair<int, int>> v;
            int last = -1;
            while (temp--) {
                auto p1 = pq.top();
                pq.pop();
                if (last != -1 && p1.first != last + 1)
                    return false;
                if (p1.second > 1)
                    v.push_back({p1.first, p1.second - 1});
                last = p1.first;
            }
            for (auto i : v)
                pq.push(i);
        }
        return true;
    }
};