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
    int n, k, x;
    cin >> n >> k >> x;
    vi a(n);
    f(i, n) cin >> a[i];
    sort(a);
    vi v;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] <= x)
            continue;
        else
        {
            int diff = a[i] - a[i - 1];
            int krequired = (diff + x - 1) / x - 1;
            v.push_back(krequired);
        }
    }
    sort(v);
    int sum = 0;
    for (auto i : v)
    {
        if (sum + i <= k)
            sum += i;
        else
            ans++;
    }
    cout << ans << endl;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}