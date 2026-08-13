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
    int n;
    cin >> n;
    vi v(n);
    f(i, n) cin >> v[i];
    if (n == 1)
    {
        cout << v[0] << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i] % v[i - 1] == 0)
        {
            if (v[i] != 1 && v[i - 1] != 1)
                v[i]++;
            else if (v[i] != 1)
            {
                if (i > 1)
                {
                    if (v[i - 2] == 2)
                    {
                        v[i - 1] = 3;
                        if (v[i] % v[i - 1] == 0)
                            v[i]++;
                    }
                    else
                    {
                        v[i - 1]++;
                        if (v[i] % v[i - 1] == 0)
                            v[i]++;
                    }
                }
                else
                {
                    v[i - 1]++;
                    if (v[i] % v[i - 1] == 0)
                        v[i]++;
                }
            }
            else
            {
                 if (i > 1)
                  {
                    if (v[i - 2] == 2)
                    {
                        v[i - 1] = 3;
                        if (v[i] % v[i - 1] == 0)
                            v[i]++;
                    }
                    else
                    {
                        v[i-1]=2;
                    }
                }
                else
                {
                    v[i-1]++;
                }
 
            }
        }
    }
    for (auto i : v)
        cout << i << " ";
    cout << endl;
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