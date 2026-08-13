class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        bool sign = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = true;
        long long n = abs(dividend*1LL);
        long long  d = abs(divisor*1LL);
        // find n / d;
        long long ans = 0;
        int i = 0;
        if (n == d)
            ans = 1;
        else if (n < d)
            ans = 0;
        else

        { 
            while(n>=d)
            {
                int cnt = 0;
                while(n>= (d << (cnt)))
                {
                    cnt++;
                }
                ans+=  (1<<(cnt-1));
                n=n-(d  << (cnt -1));
            }
        }
        if (dividend == INT_MIN && divisor == -1)
    return INT_MAX;
        if ((ans == (1LL<<31)) && (!sign)) 
            return  INT_MAX;
        if ((ans == (1LL<<31)) && sign ) 
            return  INT_MIN;
        return sign ? -1 * ans : ans;
    }
};