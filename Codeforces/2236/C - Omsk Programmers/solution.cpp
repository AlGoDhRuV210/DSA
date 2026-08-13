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
    int a, b;
    cin >> a >> b;
    int x;
    cin >> x;
    int ans = 0;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (a > b)
        swap(a, b);
    // b>a
    ans = b - a;
    int cnt = 0;
    
 
    while (a != b)
    {
        if (b > a)
        {
            while (b > a)
            {
                
                ans = min(ans, cnt + abs(a - b));
                b = b / x;
                cnt++;
            }
            ans = min(ans, cnt + abs(a - b));
        }
        else if (a > b)
        {
            while (a > b)
            {
                ans = min(ans, cnt + abs(a - b));
                a = a / x;
                cnt++;
            }
            ans = min(ans, cnt + abs(a - b));
        }
    }
    cout<<ans<<endl;
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