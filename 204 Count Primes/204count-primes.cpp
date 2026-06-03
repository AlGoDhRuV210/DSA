class Solution {
public:
bool prime(int n )
{
    for(int i = 2; i*i<=n;i++)
    {
        if(n%i==0) return false;
    } 
    return true;
}
int countPrimes(int n) {
        int ans = 0;
        if(n==0 || n==1) return 0;
        
        vector<bool> isprime(n,true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i = 2 ; i*i<= n ; i++)
        {
            if(isprime[i]==false) continue;
                int cnt=i;
                while(cnt*i<n)
                {
                    isprime[cnt*i]=false;
                    cnt++;
                }
        
            
        }
        for(auto i : isprime)
            if(i) ans++;
            return ans;
        

        
    }
};