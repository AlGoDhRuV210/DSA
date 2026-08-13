class Solution
{
public:
    int maxDigitRange(vector<int> &nums)
    {
        int range = -1;
        int ans = 0;
        for (auto i : nums)
        {
            int mx = -1;
            int mn = 11;
            int temp = i;
            while (i > 0)
            {
                mx = max(mx, i % 10);
                mn = min(mn, i % 10);
                i /= 10;
            }
           if(mx-mn>range)
           {
            ans=temp;
            range=mx-mn;
           }
           else if((mx-mn)==range)
           ans+=temp;
        }
        return ans;
         
    }
};