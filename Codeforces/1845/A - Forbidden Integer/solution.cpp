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
    int n, k, x;
    cin >> n >> k >> x;
    if (k == 1)
    {
        cout << "NO" << endl;
        return;
    }
    if (k == 2)
    {
        if (x == 1 && n % 2 == 1)
        {
            cout << "NO" << endl;
            return;
        }
        else if(x!=1)
        {
            cout << "YES" << endl;
            cout << n << endl;
            while (n--)
                cout << 1 << " ";
            cout << endl;
            return;
        }
        else 
        {
            cout << "YES" << endl;
            cout << n / 2 << endl;
            int c = n / 2;
            while (c--)
                cout << 2 << " ";
            cout << endl;
            return;
        }
    }
    // k>2
    if (x == 1)
    {
        if (n % 2 == 0)
        {
            cout << "YES" << endl;
            cout << n / 2 << endl;
            int y = n / 2;
            while (y--)
                cout << 2 << " ";
            cout << endl;
            return;
        }
        else
        {
            cout << "YES" << endl;
            cout << (n - 1) / 2 << endl;
            cout << 3 << " ";
            int z = (n - 3) / 2;
            while (z--)
                cout << 2 << " ";
            cout << endl;
            return;
        }
    }
    else
    {
          cout << "YES" << endl;
            cout << n << endl;
            while (n--)
                cout << 1 << " ";
            cout << endl;
            return;
 
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