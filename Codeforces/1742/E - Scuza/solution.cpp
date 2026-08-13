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
    int n, q;
    cin >> n >> q;
    vi a(n);
 
    f(i, n) cin >> a[i];
    vi v(q);
    f(i, q) cin >> v[i];
    vi prefixmax(n),prefixsum(n);
    prefixmax[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefixmax[i] = max(prefixmax[i - 1], a[i]);
    }
    prefixsum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefixsum[i] = prefixsum[i - 1] + a[i];
    }
    vi ans(q, 0);
    for (int i = 0; i < q; i++)
    {
        int ele = v[i];
        // find largest index in premax such that premax[index]>ele
        int low = 0;
        int high = n - 1;
        int possible = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (prefixmax[mid] <= ele)
            {
                possible = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (possible != -1)
        ans[i]=prefixsum[possible];
 
    }
 
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
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