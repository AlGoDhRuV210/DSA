class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int ans = 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int mn = intervals[0][0];
        int mx = intervals[0][1];
        if (n == 1)
            return 0;
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < mx)
            {
                ans++;
                if(intervals[i][1]<mx)
                {
                     mn = intervals[i][0];
                    mx = intervals[i][1];
                }
 
            }
            else
            {
                mn = intervals[i][0];
                mx = intervals[i][1];
            }
        }

        return ans;
    }
};