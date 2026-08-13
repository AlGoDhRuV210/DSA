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
 
void solve()
{
    int n;
    cin >> n;
    vi a(n);
 
    f(i, n) cin >> a[i];
    int flag = 0;
    for (int i = 1; i < n; i++)
    {
        if(a[i]<a[i-1])
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        cout<<0<<endl; 
        return;
    }
    
    if (a[n - 2] > a[n - 1])
    {
        cout << -1 << endl;
        return;
    }
    int m = n - 2;
    for (int i = 0; i < n - 2; i++)
    {
        a[i] = a[n - 2] - a[n - 1];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << m << endl;
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << " " << n - 1 << " " << n << endl;
    }
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