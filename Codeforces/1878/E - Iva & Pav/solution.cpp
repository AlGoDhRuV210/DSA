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
#define rev(x) reverse(all(x))
#define asort(x) sort(all(x))
#define dsort(x) sort(all(x), greater<>())
#define int long long
#define double long double
#define endl '
'
 
long long gcd(long long a, long long b)
{
    while (b)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
int a[200001];
int pre[31][200001];
 
int check(int l, int r)
{
    int ans = 0;
    for (int i = 0; i < 31; i++)
    {
        if (pre[i][r] - pre[i][l - 1] >= r - l + 1)
            ans += (1LL << i);
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
 
    f(i, n)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
 
    for (int i = 0; i < 31; i++)
    {
        pre[i][0] = 0;
        for (int j = 0; j < n; j++)
        {
            if ((1LL << i) & a[j])
            {
                pre[i][j + 1] = pre[i][j] + 1LL; // no of ones
            }
            else
                pre[i][j + 1] = pre[i][j];
        }
    }
 
    while (q--)
    {
        int l, k;
        cin >> l >> k;
 
        int low = l;
        int high = n;
        int ans = l;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
 
            if (check(l, mid) >= k)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (ans != l || a[l -1 ] >= k)
            cout << ans << " ";
        else
            cout << -1 << " ";
    }
    cout << endl;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}