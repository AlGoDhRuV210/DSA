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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
void solve()
{
    int x;
    cin >> x;
    int a = 1, b = x;
    int mx = max(a, b);
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int d = i;
            if (lcm(d, x / d) == x)
            {
                if (max(d, x / d) < mx)
                {
                    a = d;
                    b = x / d;
                }
            }
            if ((x / i) != i)
            {
                int d = x / i;
                if (lcm(d, x / d) == x)
                {
                    if (max(d, x / d) < mx)
                    {
                        a = d;
                        b = x / d;
                    }
                }
            }
        }
    }
    cout << a << " " << b << endl;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}