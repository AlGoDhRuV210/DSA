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
    int n;
    cin >> n;
 
    vi a(n);
    f(i, n) cin >> a[i];
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
 
    vi pre_odd(n, 0), pre_even(n, 0);
    pre_even[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            pre_even[i] = pre_even[i - 1] + a[i];
            pre_odd[i] = pre_odd[i - 1];
        }
        else
        {
            pre_odd[i] = pre_odd[i - 1] + a[i];
            pre_even[i] = pre_even[i - 1];
        }
    }
 
    vi pre_even_minus_odd(n);
    for (int i = 0; i < n; i++)
    {
        pre_even_minus_odd[i] = pre_even[i] - pre_odd[i];
    }
    asort(pre_even_minus_odd);
    for (int i = 0; i < n - 1; i++)
    {
        if ((pre_even_minus_odd[i] == 0) || (pre_even_minus_odd[i] == pre_even_minus_odd[i + 1]))
        {
            cout << "YES" << endl;
            return;
        }
    }
    if (pre_even_minus_odd[n - 1] == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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