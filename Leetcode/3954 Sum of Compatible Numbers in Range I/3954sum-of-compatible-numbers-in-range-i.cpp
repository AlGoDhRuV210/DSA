class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;
        for(int i = max(0,min(k-n,n-k));i<=k+n;i++)
            {
            if(abs(n-i)<=k &&  ( (n&i) == 0 )) sum+=i;
            }
        return sum;
    }
};