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
bool check(int mid, vector<pair<int, int>> &a)
{
    int power = mid;
    for (auto i : a)
    {
        if (power < i.first)
            return false;
        power += i.second;
    }
    return true;
}
 
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    int mx = -1;
    int mn = INT_MAX;
 
 
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int need = 0;
        int m = k;
        int j = 0;
        while (k--)
        {
            int x;
            cin >> x;
            mn=min(mn,x);
            mx=max(mx,x);
 
            need = max(need, x - j + 1);
            j++;
        }
        a.pb({need, m});
    }
    asort(a);
    int low = mn + 1;
    int high = mx + 1;
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(mid, a))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
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