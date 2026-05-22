class Solution {
public:
double solve(double x , long long N)
{
    if(N==0LL) return 1;
    if(N==1LL) return x;
    if(N%2==1LL)
    return x * solve(x,N-1);
    else 
    return solve(x*x,N/2);


}
    double myPow(double x, int n) {
        if(x==1) return x;
        long long N= n;
        if(x==-1 && n%2==0) return 1;
        if(x==-1 && n%2==1) return -1;
        if(N<0) return solve(1/x,-N); 
        return solve(x,N);
    }
};