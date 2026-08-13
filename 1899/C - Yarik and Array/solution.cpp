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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << a[0] << endl;
        return;
    }
    int ans = INT_MIN;
    int cur_sum = a[0];
    ans = max(ans, cur_sum);
    for (int i = 1; i < n; i++)
    {
        // if (i == 1 && cur_sum < 0)
        // {
        //     ans = cur_sum;
        //     cur_sum = a[1];
        //     continue;
        // }
        if(cur_sum<0)
        {
            ans = max(ans, cur_sum);
            cur_sum=a[i];
            ans = max(ans, cur_sum);
            continue;
            
        }
        if (((abs(a[i]) % 2) != (abs(a[i - 1]) % 2)) && (cur_sum + a[i] >= 0))
        {
            cur_sum += a[i];
            ans = max(ans, a[i]);
            ans = max(ans, cur_sum);
        }
        else
        {
            cur_sum = a[i];
            ans = max(ans, cur_sum);
            
        }
    }
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