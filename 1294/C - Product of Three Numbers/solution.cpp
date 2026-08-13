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
 
void solve()
{
    int n;
    cin >> n;
    int temp = n;
    unordered_map<int, int> mpp;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                mpp[i]++;
                n /= i;
            }
        }
    }
    if (n > 1)
        mpp[n]++;
    if (mpp.size() == 1)
    {
        for (auto i : mpp)
        {
            if (i.second >= 6)
            {
                // int x = (pow(i.first, i.second)) / (pow(i.first, 3));
                cout << "YES" << endl;
                cout << i.first << " " << i.first * i.first << " " << temp / (i.first * i.first * i.first) << endl;
            }
            else
                cout << "NO" << endl;
            return;
        }
    }
    if (mpp.size() == 2)
    {
        pair<int, int> p1, p2;
        for (auto i : mpp)
        {
            p1 = p2;
            p2 = i;
        }
        if (p1.second + p2.second < 4)
        {
            cout << "NO" << endl;
        }
        else
        {
            // int x = (pow(p1.first, p1.second) * pow(p2.first, p2.second)) / (p1.first * p2.first);
            cout << "YES" << endl;
            cout << p1.first << " " << p2.first << " " << temp / (p1.first * p2.first) << endl;
        }
        return;
    }
    // mpp.size()>=3
    cout << "YES" << endl;
    int cnt = 0;
    int tt = 1;
    for (auto i : mpp)
    {
        if (cnt < 2)
        {
            tt = tt * i.first;
            cout << i.first << " ";
            cnt++;
        }
        else
            break;
    }
    cout << temp / tt << endl;
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