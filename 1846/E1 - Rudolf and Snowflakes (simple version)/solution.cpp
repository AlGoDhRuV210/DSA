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
si s;
void precompute()
{
    for (int k = 2; k < 1000; k++)
    {
        int sum = 1 + k;
        int p = k;
        for (int j = 2; j <= 20; j++)
        {
            if (p > 1000000 / k)
                break;
            p *= k;
            sum += p;
            if (sum <= 1000000)
                s.insert(sum);
        }
    }
}
 
void solve()
{
    int n;
    cin >> n;
 
    if (s.find(n) != s.end())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}