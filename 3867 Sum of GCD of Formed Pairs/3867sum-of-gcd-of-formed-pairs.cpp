class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixmax(n), prefixgcd(n);
        prefixmax[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefixmax[i] = max(nums[i], prefixmax[i - 1]);
        }
        for (int i = 0; i < n; i++)
        {
            prefixgcd[i] = __gcd(nums[i], prefixmax[i]);
        }

        sort(prefixgcd.begin(), prefixgcd.end());
        long long ans = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if(n-i-1<0 || n-i-1>n)
            continue;
            ans += __gcd(prefixgcd[i], prefixgcd[n - i - 1]);
        }
        return ans;
    }
};