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
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define f2(i, a, b, c) for (int i = a; i <= b; i += c)
#define vi vector<long long>
#define vs vector<string>
#define vpii vector<PII>
#define mii map<int, int>
#define si set<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define asort(x) sort(all(x))
#define int long long
#define pii pair<int, int>
 
#define Its ios::sync_with_stdio(false);
#define Dhruv cin.tie(nullptr);
#define here cout.tie(nullptr);
 
using namespace std;
 
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
pii intersection(pii a, pii b)
{
    int c = max(a.first, b.first);
    int d =min(a.second, b.second);
    return {c,d};
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vi a(n);
    f(i, n) cin >> a[i];
    pii cur = {a[0]-x,a[0]+x};
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        pii p = {a[i]-x,a[i]+x};
        if(p.second<cur.first || cur.second<p.first) 
        {
           ans++;
           cur=p;
        }
        else
        {
            cur=intersection(p,cur);
        }
    
    }
    cout<<ans<<" "<<endl;
    
}
 
int32_t main()
{
    Its Dhruv here int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}