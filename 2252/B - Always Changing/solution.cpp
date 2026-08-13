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
 
class DisjointSet
{
private:
    vector<int> parent, rank, size;
 
public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        size.assign(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
 
    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
 
    void unionByRank(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (u == v)
            return;
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
 
    void unionBySize(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (u == v)
            return;
        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }
        else
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
 
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ones = 0;
    int zeros = 0;
    for (auto i : s)
    {
        if (i == '0')
            zeros++;
        else
            ones++;
    }
    int p1 = 0, p2 = 0;
    int last;
    if (s[0] == '0')
    {
        last = 0;
    }
    else
    {
        last = 1;
    }
    for (int i = 1; i < n; i++)
    {
        /* code */
        if (s[i] - '0' == last)
        {
            if (last == 1)
                p2++;
            else
                p1++;
        }
        else
        {
            last = s[i] - '0';
        }
    }
    if (p1 == 0 && p2 == 0)
    {
        cout << 0 << endl;
        return;
    }
 
    ones -= p2;
    zeros -= p1;
    int diff = p1 - p2;
 
    int ans = p1 + p2;
    if (diff > 0)
    {
        int need = diff - 1;
        if (need < 0)
            need = 0;
        if (ones < need)
        {
            cout << -1 << endl;
            return;
        }
        ones -= need;
        ans += need;
    }
    else if (diff < 0)
    {
        int need = -diff - 1;
        if (need < 0)
            need = 0;
        if (zeros < need)
        {
            cout << -1 << endl;
            return;
        }
        zeros -= need;
 
        ans += need;
    }
    if (abs(ones - zeros) > 1)
    {
        cout << -1 << endl;
        return;
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
        solve();
    return 0;
}