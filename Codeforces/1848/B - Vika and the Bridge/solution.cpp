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
 
using namespace std;
 
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
 
void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    f(i, n) cin >> a[i];
    int ans = INT_MAX;
    if (k == 1)
    {
        cout << 0 << endl;
        return;
    }
 
    vi last(k, -1);
    vi maxstep(k, -1), max_2step(k, -1);
    for (int i = 0; i < n; i++)
    {
        int step = i - last[a[i] - 1] - 1; // steps
        if (step > maxstep[a[i] - 1])
        {
            max_2step[a[i] - 1] = maxstep[a[i] - 1];
            maxstep[a[i] - 1] = step;
        }
        else if (step > max_2step[a[i] - 1])
            max_2step[a[i] - 1] = step;
 
        last[a[i] - 1] = i;
    }
 
    for (int i = 1; i <= k; i++)
    {
        int step = n - last[i - 1] - 1; // steps
        if (step > maxstep[i - 1])
        {
            max_2step[i - 1] = maxstep[i - 1];
            maxstep[i - 1] = step;
        }
        else if (step > max_2step[i - 1])
            max_2step[i - 1] = step;
    }
    for (int i = 0; i < k; i++)
    {
        ans = min(ans, max(maxstep[i] / 2, max_2step[i]));
    }
    cout << ans << endl;
}
 
int32_t main()
{
    Its Dhruv   int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}