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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zero = 0;
    int one = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j && s[i] == s[i + 1])
        i++;
    while (i <= j && s[j] == s[j - 1])
        j--;
    if (i > j)
    {
        cout << 1 << endl;
        return;
    }
 
    if (s[0] == s[n - 1])
        cout << 1 << endl;
    else
    {
        i++;
        while (i < j)
        {
            if (s[i] == '0')
                zero++;
            else
                one++;
            i++;
        }
        if (zero && one)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
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