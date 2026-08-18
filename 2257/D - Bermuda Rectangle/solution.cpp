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
    int s, q;
    cin >> s >> q;
    vi fact;
    for (int i = 1; i * i <= s; i++)
    {
        /* code */
        if (s % i == 0)
        {
            fact.push_back(i);
            if (s / i != i && s % (s / i) == 0)
                fact.push_back(s / i);
        }
    }
    asort(fact);
    int n = fact.size();
    vi prefix(n + 1, 0);
    // int prev_side = 0;
 
    // for (int i = 0; i < prefix.size(); ++i)
    // {
    //     int cur = (prefix[i] - prev_side) * (s / prefix[i]);
    //     prefix[i + 1] = cur + prefix[i];
    //     prev_side = prefix[i];
    // }
    int prev_side = 0;
 
    for (int i = 0; i < fact.size(); ++i)
    {
        int cur = (fact[i] - prev_side) * (s / fact[i]);
        prefix[i + 1] = prefix[i] + cur;
        prev_side = fact[i];
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x > s)
        {
            x = s;
        }
        if (y > s)
        {
            y = s;
        }
        // if (x >= fact.back() && y >= fact.back())
        // {
        //     cout << s << endl;
        //     continue;
        // }
        int ans = 0;
        int xup = lower_bound(all(fact), x) - fact.begin();
        if (xup != fact.size() && y <= s / fact[xup])
        {
            cout << x * y << '
';
            continue;
        }
        if (xup != fact.size())
        {
            ans = prefix[xup + 1];
            ans -= (fact[xup] - x) * (s / (fact[xup]));
        }
        else
            ans += prefix.back();
 
        int y_upb = lower_bound(fact.begin(), fact.end(), y) - fact.begin();
        if (y_upb != fact.size())
        {
            int upper_ladder = prefix.back() - prefix[y_upb + 1];
            ans -= upper_ladder;
            ans -= (fact[y_upb] - y) * (s / fact[y_upb]);
        }
 
        cout << ans << endl;
    }
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