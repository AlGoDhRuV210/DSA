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
#define rev(x) reverse(all(x))
#define asort(x) sort(all(x))
#define dsort(x) sort(all(x), greater<>())
#define int long long
#define double long double
#define endl '
'
 
long long gcd(long long a, long long b)
{
    while (b)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
 
bool check(vpii &v, int k)
{
 
    int mn = 0;
    int mx = 0;
 
    for (int i = 0; i < v.size(); i++)
    {
        int l = v[i].first;
        int r = v[i].second;
 
        mx = min(r, mx + k);
        mn = max(l, mn - k);
 
        if (mx < l || mn > r)
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vpii v(n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        v[i] = {l, r};
    }
    int l = 0;
    int h = 1000000000;
    int ans = h;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (check(v, m))
        {
            ans = m;
            h = m - 1;
        }
        else
            l = m + 1;
    }
 
    cout << ans << endl;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}