class Solution
{
public:
    void helper(int n, int k, vector<string> &v, string cur, int index, int cost)
    {
        if (cost > k)
            return;
        if (index == n)
        {
            if (cost <= k)
                v.push_back(cur);
            return;
        }
        else if (index > n)
            return;
        helper(n, k, v, "0" + cur, index + 1, cost);
        helper(n, k, v, "01" + cur, index + 2, cost + (n - 1 - index));
        if (index == n - 1)
            helper(n, k, v, "1" + cur, index + 1, cost + (n - 1 - index));
    }
    vector<string> generateValidStrings(int n, int k)
    {
        vector<string> v;
        helper(n, k, v, "", 0, 0);
        return v;
    }
};
