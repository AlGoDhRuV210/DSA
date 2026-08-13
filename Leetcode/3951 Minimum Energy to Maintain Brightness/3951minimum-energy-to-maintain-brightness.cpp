class Solution
{
public:
    long long minEnergy(int n, int brightness, vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> neww;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (i < intervals.size() - 1 && intervals[i][1] >= intervals[i + 1][0])
            {
                if (neww.empty())
                    neww.push_back({intervals[i][0], max(intervals[i + 1][1], intervals[i][1])});
                else if (neww.back()[1] < intervals[i][0])
                    neww.push_back({intervals[i][0], max(intervals[i + 1][1], intervals[i][1])});
                else if (neww.back()[1] == intervals[i][0])
                    neww.back()[1] = max(intervals[i + 1][1], intervals[i][1]);
                else if (neww.back()[1] > intervals[i][0])
                    neww.back()[1] = max(max(intervals[i + 1][1], intervals[i][1]), neww.back()[1]);

                i++;
            }
            else
            {
                 if (neww.empty())
                    neww.push_back({intervals[i][0],  intervals[i][1]});
                else if (neww.back()[1] < intervals[i][0])
                    neww.push_back({intervals[i][0],  intervals[i][1]});
                else if (neww.back()[1] == intervals[i][0])
                    neww.back()[1] =   intervals[i][1];
                else if (neww.back()[1] > intervals[i][0])
                    neww.back()[1] = max( intervals[i][1], neww.back()[1]);

            }
        }
        int length=0;
        for(auto i : neww)
        {
            length+=i[1]-i[0]+1;
        }
        long long ans=0;
         int bulb=0;
        while(min(3*bulb,n) < brightness)
        bulb++;
        ans=1LL*bulb*length;
        return ans;

    }
};
