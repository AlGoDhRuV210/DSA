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
 
void solve()
{
    int n, q;
    cin >> n >> q;
    vi a(n);
    f(i, n) cin >> a[i];
    vi b(n, -1);
    b[0] = a[0] % 2;
    for (int i = 1; i < n; i++)
    {
        // 1 for odd , 0 for even;
        b[i] = (b[i - 1] + a[i]%2) % 2;
    }
 
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int sum = b[n-1];
        sum += (((k % 2) * (r - l + 1)) % 2);
        if (l > 1)
            sum += ((b[r - 1] - b[l - 2]) % 2);
        else
            sum += b[r - 1] % 2;
        if (sum % 2 == 0)
            cout << "NO";
        else
            cout << "YES"; cout<<endl;
    }
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