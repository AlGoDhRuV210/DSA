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
    vi a(n + 1);
    int sum = 0;
    f(i, n)
    {
        cin >> a[i + 1];
        sum += a[i + 1];
    }
    mii mpp;
    int all = -1;
    while (q--)
    {
        int m;
        cin >> m;
        if (m == 1)
        {
            int i, x;
            cin >> i >> x;
            if (mpp.find(i) != mpp.end())
                sum = sum - mpp[i] + x;
            else if (all == -1)
                sum = sum - a[i] + x;
            else
                sum = sum - all + x;
            mpp[i] = x;
            cout << sum << endl;
        }
        else  
        {
            int x;
            cin >> x;
            mpp.clear();
            all = x;
            sum = x * n;
            cout << sum << endl;
        }
    }
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
     
        solve();
    
    return 0;
}