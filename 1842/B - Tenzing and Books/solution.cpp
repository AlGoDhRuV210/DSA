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
 
void solve()
{
    int n, x;
    cin >> n >> x;
    vi a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    if (x == 0)
    {
        cout << "YES" << endl;
        return;
    }
    vi prefixa(n);
    prefixa[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefixa[i] = prefixa[i - 1] | a[i];
    }
    vi prefixb(n);
    prefixb[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        prefixb[i] = prefixb[i - 1] | b[i];
    }
    vi prefixc(n);
    prefixc[0] = c[0];
    for (int i = 1; i < n; i++)
    {
        prefixc[i] = prefixc[i - 1] | c[i];
    }
    bool ans = false;
    vi bits;
    int temp = x;
    int m = 0;
    int v=32;
    while (v--)
    {
        if ((temp & 1) == 0)
            bits.pb(m);
        m++;
        temp >>= 1;
    }
    int cur = 0;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        for (auto k : bits)
        {
            if ((a[i] & (1LL << k)) != 0)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
        cur = cur | a[i];
    }
    flag= true;
    for (int i = 0; i < n; i++)
    {
        for (auto k : bits)
        {
            if ((b[i] & (1LL << k)) != 0)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
        cur = cur | b[i];
    }
    flag=true;
    for (int i = 0; i < n; i++)
    {
        for (auto k : bits)
        {
            if ((c[i] & (1LL << k)) != 0)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
        cur = cur | c[i];
    }
 
        if(cur==x) ans=true;
 
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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