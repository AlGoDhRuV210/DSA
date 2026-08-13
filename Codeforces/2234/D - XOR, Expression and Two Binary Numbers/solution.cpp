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
int setbits(string n)
{
    int cnt = 0;
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] == '1')
            cnt++;
    }
 
    return cnt;
}
string fun(string a, string b)
{
    string s = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
            s += "0";
        else
            s += "1";
    }
    return s;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string x, y;
    cin >> x >> y;
    int x1 = setbits(x) * (n - setbits(x));
    int y1 = setbits(y) * (n - setbits(y));
 
    int xr = setbits(fun(x, y)) * (n - setbits(fun(x, y)));
 
    int ans = 0;
    int m = (1 << k) + 1;
    ans = (m / 3) * xr + ((m - m / 3) / 2) * (x1 + y1);
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