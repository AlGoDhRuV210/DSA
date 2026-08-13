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
const int mod = 1000000000;
void solve()
{
    int n;
    cin >> n;
    int m = (n * (n - 1)) / 2;
    vi b(m);
    vpii v;
 
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(b);
 
    vi a;
    a.pb(mod);
    int cnt = 1;
    int ele = b[m - 1];
    for (int i = m - 2; i >= 0; i--)
    {
        if (b[i] == ele)
            cnt++;
        else
        {
            int s = a.size();
            int temp = 0;
            int noof = 0;
            while (cnt != 0)
            {
                noof++;
                cnt -= (s + temp);
                temp++;
            }
            for (int j = 0; j < noof; j++)
            {
                a.pb(ele);
            }
 
            ele = b[i];
            cnt = 1;
        }
    }
    int s = a.size();
    int temp = 0;
    int noof = 0;
    while (cnt != 0)
    {
        noof++;
        cnt -= (s + temp);
        temp++;
    }
    for (int j = 0; j < noof; j++)
    {
        a.pb(ele);
    }
    sort(a);
    for (auto i : a)
        cout << i << " ";
    cout << endl;
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