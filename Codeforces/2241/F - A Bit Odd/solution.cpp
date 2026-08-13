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
    bool alice_wins = false;
 
    // Pass 1: Check if any '1' has an odd number of '0's to its right
    int count_zeros = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            count_zeros++;
        }
        else if (s[i] == '1')
        {
            if (count_zeros % 2 != 0)
            {
                alice_wins = true;
                break;
            }
        }
    }
 
    // Pass 2: Check if any '0' has an odd number of '1's to its left
    if (!alice_wins)
    {
        int count_ones = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                count_ones++;
            }
            else if (s[i] == '0')
            {
                if (count_ones % 2 != 0)
                {
                    alice_wins = true;
                    break;
                }
            }
        }
    }
 
    if (alice_wins)
    {
        cout << "Alice
";
    }
    else
    {
        cout << "Bob
";
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