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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a);
    vpii v;
    int ele = a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == ele)
            cnt++;
        else
        {
            v.push_back({a[i - 1], cnt});
            cnt = 1;
            ele = a[i];
        }
    }
    v.push_back({a[n - 1], cnt});
    //
    if ((v[v.size() - 1].second % 2) == 0)
    {
        cout << "YES" << endl;
        return;
    }
    int cur = 1; // even
    for (int i = v.size() - 2; i >= 0; i--)
    {
 
        if (v[i].first + k < v[i + 1].first)
        {
            if ((v[i].second % 2) == 0)
            {
                cout << "YES" << endl;
                return;
            }
            cur=v[i].second % 2;
 
        }
        else
        {
            if(cur==1)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
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