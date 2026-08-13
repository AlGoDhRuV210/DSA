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
{   int n ;
    cin>>n;
    vi a(n);
 
    if(n==2) {cout<<1<<" "<<0<<endl; return; }
    if(n==3) {cout<<1<<" "<<0<<" "<<2<<endl; return; }
    int f =   floor(log2(n-1));
    int s = 1<<f;
    for (int i = 0; i < n; i++)
    {
        a[i]=i;
    }
    int i =0;
    while((((n-1) & (1LL<<i)) == 0)) i++;
    int x = (1LL<<s);// 2^i
    for (int j = 0; j < s; j++)
    {
        a[j]=j+1;
    }
    a[s-1]=0;
 
    for(auto i : a)
    cout<<i<<" "; cout<<endl;
    
    
 
    
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