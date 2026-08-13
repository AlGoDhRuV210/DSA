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
    int two = 0, five = 0;
    int temp = n;
    while (n > 0 && n % 10 == 0)
        n = n / 10;
    if (n > 0 && n % 2 == 0)
    {
        while (n > 0 && n % 2 == 0)
        {
            two++;
            n = n / 2;
        }
    }
    if (n > 0 && n % 5 == 0)
    {
        while (n > 0 && n % 5 == 0)
        {
            five++;
            n = n / 5;
        }
    }
    int cur = 1;
    n = temp;
 
    if (two)
    {
        while (two-- && cur * 5 <= m)
        {
            cur = cur * 5;
            n = n * 5;
        }
    }
    if (five)
    {
        while (five-- && cur * 2 <= m)
        {
            cur = cur * 2;
            n = n * 2;
        }
    }
    while (cur * 10 <= m)
    {
        cur = cur * 10;
        n = n * 10;
    }
    if ((m / cur) > 1)
        n = n * (m / cur);
    if (n % 10 == 0)
        cout << n << endl;
    else
        cout << temp * m << endl;
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