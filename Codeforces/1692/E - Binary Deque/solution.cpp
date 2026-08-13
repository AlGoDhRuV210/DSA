#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;
 
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
#define vi vector<long long>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define mii map<int, int>
#define mci map<char, int>
#define umci unordered_map<char, int>
#define umii unordered_map<int, int>
#define si set<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sort(x) sort(x.begin(), x.end())
#define int long long
 
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
 
void solve()
{
    int n, s;
    cin >> n >> s;
    vi a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        /* code */ cin >> a[i];
        sum += a[i];
    }
    vi pre;
    vi suf;
    pre.pb(0);
    suf.pb(0);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            pre.pb(i);
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 1)
            suf.pb(n - i + 1);
    }
    if (s > sum)
    {
        cout << -1 << endl;
        return;
    }
    if (s == sum)
    {
        cout << 0 << endl;
        return;
    }
    int rem = sum-s;
    int ans = n+1;
    int p = pre.size();
    int q = suf.size();
    for (int i = 0; i <=rem; i++)
    {
        ans=min(ans,pre[i]+suf[rem-i]);
    }
    cout<<ans<<endl;
    
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}