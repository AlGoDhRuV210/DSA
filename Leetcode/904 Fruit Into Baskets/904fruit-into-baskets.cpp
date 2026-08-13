class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int ele1 = -1;
        int ele2 = -1;
        int last1 = -1; // last occurence of ele1
        int last2 = -1; // last occurence of ele2
        int n = fruits.size();
        int maxlen = 0;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            if (fruits[r] == ele1)
            {
                last1 = r;
                maxlen = max(maxlen, r - l + 1);
                continue;
            }
            if (fruits[r] == ele2)
            {
                last2 = r;
                maxlen = max(maxlen, r - l + 1);
                continue;
            }
            if (ele1 == -1 && fruits[r] != ele2)
            {
                ele1 = fruits[r];
                last1 = r;
            }
            else if (ele2 == -1 && fruits[r] != ele1)
            {
                ele2 = fruits[r];
                last2 = r;
            }
            else if (ele1 != fruits[r] && ele2 != fruits[r])
            {
                if (last1 < last2)
                {
                    l = last1 + 1;
                    ele1 = fruits[r];
                    last1 = r;
                }
                else
                {
                    l = last2 + 1;
                    ele2 = fruits[r];
                    last2 = r;
                }
            }
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};