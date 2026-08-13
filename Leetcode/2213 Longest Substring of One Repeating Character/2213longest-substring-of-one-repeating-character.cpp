class Solution {
public:
    struct Node {
        int len;
        int pref;
        int suff;
        int best;

        char left;
        char right;

        Node() {
            len = pref = suff = best = 0;
            left = right = '#';
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        if (a.len == 0)
            return b;
        if (b.len == 0)
            return a;

        Node res;

        res.len = a.len + b.len;

        res.left = a.left;
        res.right = b.right;

        res.pref = a.pref;

        if (a.pref == a.len && a.right == b.left) {
            res.pref = a.len + b.pref;
        }
        res.suff = b.suff;

        if (b.suff == b.len && a.right == b.left) {
            res.suff = b.len + a.suff;
        }

        res.best = max(a.best, b.best);
        if (a.right == b.left) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(int idx, int l, int r, string& s) {

        if (l == r) {

            seg[idx].len = 1;
            seg[idx].pref = 1;
            seg[idx].suff = 1;
            seg[idx].best = 1;

            seg[idx].left = s[l];
            seg[idx].right = s[l];

            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    // Update one position
    void update(int idx, int l, int r, int pos, char c) {

        if (l == r) {

            seg[idx].len = 1;
            seg[idx].pref = 1;
            seg[idx].suff = 1;
            seg[idx].best = 1;

            seg[idx].left = c;
            seg[idx].right = c;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * idx, l, mid, pos, c);
        } else {
            update(2 * idx + 1, mid + 1, r, pos, c);
        }
        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int pos = queryIndices[i];
            char c = queryCharacters[i];
            s[pos] = c;
            update(1, 0, n - 1, pos, c);
            ans.push_back(seg[1].best);
        }

        return ans;
    }
};