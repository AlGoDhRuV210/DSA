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
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(n + 1, {0, n + 1}); //{left,right}
 
    for (int i = 0; i < m; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        // p1 != p2
        if (p2 > p1)
            v[p1].second = min(v[p1].second, p2);
        else
            v[p1].first = max(v[p1].first, p2);
 
        // p2 != p1
        if (p1 > p2)
            v[p2].second = min(v[p2].second, p1);
        else
            v[p2].first = max(v[p2].first, p1);
    }
    int ans = 0;
    for (int i = 2; i <=n; i++)
    {
        /* code */
        v[i].first=max(v[i].first,v[i-1].first);
    }
    
    for (int i = 1; i <= n; i++)
    {
        // right
        int left = i - v[i].first - 1;
 
        ans += left + 1;
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