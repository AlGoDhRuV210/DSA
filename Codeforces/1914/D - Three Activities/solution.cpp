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
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define mii map<int, int>
#define si set<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sort(x) sort(x.begin(), x.end())
#define int long long
 
#define Its ios::sync_with_stdio(false);
#define Dhruv cin.tie(nullptr);
#define here cout.tie(nullptr);
 
using namespace std;
 
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
 
void solve()
{
    int n;
    cin >> n;
    vpii a, b, c;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.pb({x, i});
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        b.pb({x, i});
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        c.pb({x, i});
    }
    sort(a);
    sort(b);
    sort(c);
    vpii a1, a2, a3;
    a1.pb(a[n - 1]);
    a1.pb(a[n - 2]);
    a1.pb(a[n - 3]);
 
    a2.pb(b[n - 1]);
    a2.pb(b[n - 2]);
    a2.pb(b[n - 3]);
 
    a3.pb(c[n - 1]);
    a3.pb(c[n - 2]);
    a3.pb(c[n - 3]);
 
    int ans = 0;
    for (auto i : a1)
    {
        int sum = i.first;
        for (auto j : a2)
        {
            if (j.second == i.second)
                continue;
            for (auto k : a3)
            {
                if (k.second == i.second || k.second == j.second)
                    continue;
                ans = max(ans, sum + k.first+j.first);
            }
        }
    }
    cout<<ans<<endl;
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