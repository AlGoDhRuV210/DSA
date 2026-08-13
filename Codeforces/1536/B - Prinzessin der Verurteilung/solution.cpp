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
    // set<string> set;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         set.insert(s.substr(i, j - i + 1));
    //     }
    // }
    for (char a = 'a'; a <= 'z'; a++)
    {
        if (s.find(string(1, a)) == string::npos)
        {
            cout << string(1, a) << endl;
            return;
        }
    }
 
    // length 2
    for (char a = 'a'; a <= 'z'; a++)
    {
        for (char b = 'a'; b <= 'z'; b++)
            if (s.find(string() + a + b) == string::npos)
            {
                cout << string() + a + b << endl;
                return;
            }
    }
    // length 3
    for (char a = 'a'; a <= 'z'; a++)
 
    {
        for (char b = 'a'; b <= 'z'; b++)
 
        {
            for (char c = 'a'; c <= 'z'; c++)
 
                if (s.find(string() + a + b + c) == string::npos)
                {
                    cout << string() + a + b + c << endl;
                    return;
                }
        }
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