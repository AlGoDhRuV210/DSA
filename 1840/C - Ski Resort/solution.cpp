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
 
int fun(int i, int j, int k)
{
    int len = j-i+1;
    return ((len-k+1)* (len-k+2))/2;
}
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vi a(n);
    f(i, n) cin >> a[i];
    int i = 0;
    int j = i;
    int ans = 0;
    while (j < n && i < n)
    {
        if (a[j] <= q)
            j++;
        else
        {
 
            if (j - i >= k)
                ans += fun(i, j - 1, k);
            j++;
            i = j;
        }
    }
     if (j - i >= k)
    ans += fun(i, j - 1,k);
 
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