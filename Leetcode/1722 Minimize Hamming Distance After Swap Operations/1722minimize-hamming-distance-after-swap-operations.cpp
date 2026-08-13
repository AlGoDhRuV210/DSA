class Solution {
public:
    class DSU {
    public:
        vector<int> parent;

        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int a, int b) {
            int pa = find(a);
            int pb = find(b);
            if (pa != pb) parent[pb] = pa;
        }
    };

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        DSU dsu(n);


        for (auto &p : allowedSwaps) {
            dsu.unite(p[0], p[1]);
        }
        unordered_map<int, unordered_map<int,int>> mp;

        for (int i = 0; i < n; i++) {
            int leader = dsu.find(i);
            mp[leader][source[i]]++;
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int leader = dsu.find(i);

            if (mp[leader][target[i]] > 0) {
                mp[leader][target[i]]--;
            } else {
                ans++;
            }
        }

        return ans;
    }
};