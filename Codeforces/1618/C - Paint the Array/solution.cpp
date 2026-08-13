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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    f(i, n) cin >> a[i];
 
    int common = a[0];
    // even places os divisilbe
    for (int i = 2; i < n; i += 2)
    {
        common = gcd(common, a[i]);
    }
    bool flag = 1;
    if (common != 1)
    {
        for (int i = 1; i < n; i += 2)
        {
            if (a[i] % common == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout << common << endl;
            return;
        }
    }
    // odd places as divisible
    flag=1;
    common = a[1];
    for (int i = 3; i < n; i += 2)
    {
        common = gcd(common, a[i]);
    }
    if (common != 1)
    {
        for (int i = 0; i < n; i += 2)
        {
            if (a[i] % common == 0)
            {
                flag=0;
                break;
            }
        }
       if (flag)
        {
            cout << common << endl;
            return;
        }
    }
    cout<<0<<endl;
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