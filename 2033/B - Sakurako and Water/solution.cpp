    // ██████╗   ██████╗   ███████╗  ██████╗    █████╗   ████████╗   █████╗   ██████╗
    // ██╔══██╗  ██╔══██╗  ██╔════╝  ██╔══██╗  ██╔══██╗  ╚══██╔══╝  ██ ══██   ██╔══██╗
    // ██████╔╝  ██████╔╝  █████╗    ██║  ██║  ███████║     ██║     ██   ██   ██████╔╝
    // ██╔═══╝   ██╔══██╗  ██╔══╝    ██║  ██║  ██╔══██║     ██║     ██╔══██   ██╔══██╗
    // ██║       ██║ ╚██╗  ███████╗  ██╔══██╗  ██║  ██║     ██║      █████    ██║ ╚██╗
    // ╚═╝       ╚═╝  ╚═╝  ╚══════╝  ██████╔╝  ╚═╝  ╚═╝     ╚═╝       ╚═╝     ╚═╝  ╚═╝
    #include <bits/stdc++.h>
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("Ofast,unroll-loops")      
    using namespace std;
    #define endl "
"
    #define Code ios::sync_with_stdio(false);
    #define By cin.tie(nullptr);
    #define Dhwanit cout.tie(nullptr);
    #define vint vector<int>
    #define int long long
    #define double long double
    #define pb push_back
    #define asort(a) sort(a.begin(),a.end())
    #define dsort(a) sort(a.begin(),a.end(),greater<int>())
    #define MOD 1000000007
    #define MOD1 998244353
    template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 
    template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 
    template<typename T>T mod_inverse(T a, T n = MOD){T x,y,z=0;
               T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));} 
    #define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
    #define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
    #define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
    #define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))
 
 
 
 
    
 
    void solve(){
        int n;cin>>n;
        vector<vint>a(n+1,vint(n+1));
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
        int ans=0;
        for(int j=1;j<=n;j++){
            int t=INT_MAX;
            int x=1,y=j;
            while(x<=n && y<=n){
                if(a[x][y]<0)
                t=min(t,a[x][y]);
                x++;y++;
            }
            if(t!=INT_MAX)
            ans+=abs(t);
        }
        for(int i=2;i<=n;i++){
            int t=INT_MAX;
            int x=i,y=1;
            while(x<=n && y<=n){
                if(a[x][y]<0)
                t=min(t,a[x][y]);
                x++;y++;
            }
            if(t!=INT_MAX)
            ans+=abs(t);
        }cout<<ans<<endl;
 
    }
 
    int32_t main() {
 
 
        Code By Dhwanit 
        
        //smallest_primefactor();
       // prime();
       //precompute();
        int t;cin>>t;while(t--)
        solve();
        return 0;
    }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
    // int gcd(int a,int b) {
    //     while (b != 0) {
    //         int temp = b;
    //         b = a % b;
    //         a = temp;
    //     }
    //     return a;
    // }
 
 
 
    // const long long N = 1e9;
    // vector<long long> a(N+1,1);
    // vector<long long> primes;
    // void prime(){
    //     a[0]=a[1]=0;
    //     for (int i=2;i*i<=N;i++) {
    //         if(a[i]==1){
    //             for(int j=i*i;j<=N;j+=i) {
    //                 a[j]=0;
    //             }
    //         }
    //     }
    //     for (int i=2;i<=N;i++) {
    //         if (a[i]==1)primes.push_back(i);
    //     }
    // }
 
 
 
    //  const int N = 1e7+1;
    // int spf[N + 1];
    // void smallest_primefactor(){
    //     iota(spf,spf+N+1,0);
    // for (int i = 2; i * i <= N; i++) {
    //         if (spf[i] == i) {
    //             for (int j = i * i; j <= N; j += i) {
    //                 if (spf[j] == j)
    //                     spf[j] = i;
    //             }
    //         }
    //     }
    // }
 
 
    // string toBinary(int n) {
    //     if (n == 0) return "";
    //     return toBinary(n/2)+char((n%2)+'0');
    // }
 
 
 
    // int toDecimal(string b){
    //     int d=0;x
    //     for(char c:b)d=d*2+(c-'0');
    //     return d;
    // }
 
 
 
    // vector<vint> subset(vector<int>&p){
    //     int numsubset=1<<p.size();
    //     vector<vint>ans;
    //     vint list;
    //     for(int i=0;i<numsubset;i++){
    //         for(int j=0;j<p.size();j++){
    //             if(i &(1<<j)){
    //                 list.pb(p[j]);
    //             }
    //         }
    //         ans.pb(list);
    //         list.clear();
    //     }
    //     return ans;
    // }