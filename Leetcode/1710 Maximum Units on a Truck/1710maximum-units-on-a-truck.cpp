class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int ans = 0;
        for (auto &i : boxTypes)
            swap(i[0], i[1]);
        sort(boxTypes.begin(),boxTypes.end());
        int n = boxTypes.size();
        int i = n - 1;
        while (truckSize > 0 && i>=0)
        {
            if (boxTypes[i][1] <= truckSize)
            {
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][1];
            }
            else
            {
                ans += boxTypes[i][0] * truckSize;
                break;
            }

            i--;
        }

        return ans;
    }
};