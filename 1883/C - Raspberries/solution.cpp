#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <limits>
#include <functional>
#include <bitset>
#include <tuple>
#include <complex>
#include <math.h>
#define f(i,n) for (int i = 0; i < n; i++)
#define f1(i,a,b) for (int i = a; i <= b; i++)
#define f2(i,a,b,c) for (int i = a; i <= b; i += c)
#define vi vector<long long>
#define vs vector<string>
#define pii pair<int, int>
#define vpii vector<PII>
#define mii map<int, int>
#define si set<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define asort(x) sort(all(x))
#define int long long
 
 
 
 
#define Its ios::sync_with_stdio(false);
#define Dhruv cin.tie(nullptr);
#define here cout.tie(nullptr);
 
using namespace std;
 
 
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
 
void solve()
{   int n ,k;
    cin>>n>>k;
    vi a(n); f(i,n) cin>>a[i];
    if(k==4)
    {
        int even=0;
        int mod3=0;
        int mod4=0;
        for(auto i : a) 
        {
            if(i%2==0)  even++;
            if(i%4==3) {mod3++;}
            if(i%4==0) {mod4++;}
        }
        if(mod4) cout<<0;
        else if(even>=2) cout<<0;
        else if (even==1) cout<<1;
        else if(mod3>0) cout<<1;
        else cout<<2;
    }
    else
    {
        int y =0;int x=k-1;
         for(auto i : a) 
        {
            x=min(x,i%k);
            
           y=max(y,i%k); 
        }
        if(x==0) cout<<0; 
        else
        cout<<k-y;
    }
    cout<<endl;
}
 
 
int32_t main() {
    Its Dhruv here
    int t;
    cin >> t;
    while (t--) {
       solve();
    }
 return 0; 
}