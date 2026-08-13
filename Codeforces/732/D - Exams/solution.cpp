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
bool check(int mid, vi a, vi d)
{
    // days = mid
    mii mpp;
    for (int i = 0; i < mid; i++)
    {
        if (d[i])
            mpp[d[i]] = i;//last index of d[i] subject
    }
    int rem = 0;
    if (mpp.size() != a.size())
        return false;
 
    for (int i = 0; i < mid; i++)
    {
        if (mpp.empty())
            return true;
        if (mpp.find(d[i]) != mpp.end() && mpp[d[i]] == i)
        {
            if (rem >= a[d[i] - 1])
            {
                mpp.erase(d[i]);
                rem -= a[d[i] - 1];
            }
            else
                return false;
        }
        else
        {
            // if (d[i]) // not zero
                rem++;
        }
    }
    if (mpp.empty())
        return true;
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vi d(n), a(m);
    f(i, n) cin >> d[i];
    f(i, m) cin >> a[i];
    int low = 1;
    int high = n;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
 
        if (check(mid, a, d))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << endl;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}