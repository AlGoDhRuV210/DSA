class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> v;

        int a = newInterval[0];
        int b = newInterval[1];
        if (intervals.size() == 0)
            return {{a, b}};
        int n = intervals.size();
        int i = 0;
        if (b < intervals[0][0])
        {
            intervals.push_back({a, b});
            sort(intervals.begin(), intervals.end());
            return intervals;
        }
        while (i < n && intervals[i][1] < a)
        {
            v.push_back(intervals[i]);
            i++;
        }
        if (i == n)
        {
            intervals.push_back({a, max(b, intervals[n - 1][1])});
            return intervals;
        }
        if (intervals[i][0] > b)
        {
            v.push_back({a, b});
            v.push_back(intervals[i]);
            i++;
            while (i < n)
            {
                v.push_back(intervals[i]);
                i++;
            }
            return v;
        }
        int c = intervals[i][0];
        int d = intervals[i][1];
        if (b <= d)
        {
            intervals[i][0] = min(c, a);
            return intervals;
        }
        // b>d
        while (i < n && intervals[i][1] < b)
            i++;
        if (i == n)
        {
            v.push_back({min(c, a), b});
            return v;
        }
        // b<=intervals[i][1]
        if (intervals[i][0] > b)
        {
            v.push_back({min(a, c), b});
            v.push_back(intervals[i]);
        }
        else
        {
            v.push_back({min(a, c), intervals[i][1]});
        }

        // b>intervals[i][0]

        i++;
        while (i < n)
        {
            v.push_back(intervals[i]);
            i++;
        }
        return v;
    }
};