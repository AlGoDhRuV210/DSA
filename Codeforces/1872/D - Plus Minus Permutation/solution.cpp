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
int gcd(int x, int y)
{
    if (y == 0)
    return x;
    return gcd(y, x % y);
}
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0;
    int mx = n;
    int temp = x;
    int lcm = (x * y )/ gcd(x, y);
    int ofx = n / x;
    int ofy = n / y;
    int oflcm = n / lcm;
    ofx -= oflcm;
    ofy -= oflcm;
    if (ofx > 0)
    {
        ans += (ofx * (2 * n - ofx + 1)) / 2;
    }
    if (ofy > 0)
        ans -= (ofy * (1 + ofy)) / 2;
 
    cout << ans << endl;
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