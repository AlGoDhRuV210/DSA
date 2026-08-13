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
 
    vector<int> a(n), b(n);
 
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
 
    if (a == b)
    {
        cout << 0 << '
';
        return;
    }
 
    bool all0 = true, all1 = true;
    for (int x : a)
    {
        if (x)
            all0 = false;
    }
    for (int x : b)
    {
        if (!x)
            all1 = false;
    }
 
    if (all0)
    {
        cout << -1 << '
';
        return;
    }
 
    if (all1)
    {
        bool startAll1 = true;
        for (int x : a)
            if (!x)
                startAll1 = false;
 
        if (!startAll1)
        {
            cout << -1 << '
';
            return;
        }
    }
 
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            sum += a[i];
 
    if (sum & 1)
        cout << 1 << '
';
    else
        cout << 2 << '
';
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