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
    int n, m;
    cin >> n >> m;
    vi a(m);
    f(i, m) cin >> a[i];
    int ans = 0;
    sort(a);
    if (m == 1)
    {
        cout <<  2 << endl;
        return;
    }
    vi gaps;
    for (int i = 1; i < m; i++)
    {
        gaps.pb(a[i] - a[i - 1] - 1);
    }
    gaps.pb(n - 1 - (a[m - 1] - a[0]));
    sort(gaps);
    reverse(all(gaps));
    int days = 0;
 
    for (int i = 0; i < gaps.size(); i++)
    {
       int cur = gaps[i] - 2 * days;
        if (cur > 2)
        {
            days += 2;
            cur--;
        }
        else if (cur==1)
        {
            days += 1;
        }
        else if (cur==2)
        {
            days += 1;
            cur--;
        }
        gaps[i] = max(0LL, cur);
    }
    ans = n - accumulate(gaps.begin(), gaps.end(), 0LL);
    cout << ans << endl;
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