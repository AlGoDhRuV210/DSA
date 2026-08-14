class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        // priority_queue<pair<int, int>, vector<pair<int, int>>,
        //                greater<pair<int, int>>>
        //     pq;

        map<int, int> pq;
        for (auto i : hand)
            pq[i]++;
        while (!pq.empty()) {

            int start = pq.begin()->first;

            for (int x = start; x < start + groupSize; x++) {

                if (!pq.count(x))
                    return false;
                pq[x]--;
                if (pq[x] == 0)
                    pq.erase(x);

            }

        }
        return true;
    }
};