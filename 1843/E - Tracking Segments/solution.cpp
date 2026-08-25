#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;
 
#include <iomanip>
#include <vector>
#include <algorithm>
#include <climits>
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
    int m;
    cin >> m;
    vpii v;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        v.pb({l, r});
    }
    int q;
    cin >> q;
    vi queries;
    while (q--)
    {
        int x;
        cin >> x;
        queries.pb(x);
    }
    vi y1(n + 1, 0); // one
    vi y0(n + 1, 1); // zeros
    // for (int i = 0; i < n; i++)
    // {
    //     /* code */
    //     y0[i] = i + 1;
    // }
 
    int low = 0;
    int high = queries.size();
    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        vector<int> a0 = y0;
        vector<int> a1 = y1;
        for (int i = 0; i < mid; i++)
        {
            int ind = queries[i] - 1;
            a1[ind]++;
            a0[ind]--;
        }
        for (int i = 1; i < n; i++)
        {
            /* code */
            a1[i] += a1[i - 1];
            a0[i] += a0[i - 1];
        }
        int flag = 0;
        for (auto i : v)
        {
            int l = i.first - 1;
            int r = i.second - 1;
            int z = a0[r];
            int o = a1[r];
            if (l > 0)
            {
                z -= a0[l - 1];
                o -= a1[l - 1];
            }
 
            if (o > z)
            {
                flag = 1;
                ans = mid;
                high = mid - 1;
                break;
            }
        }
        if (mid == queries.size() && !flag)
        {
            cout << -1 << endl;
            return;
        }
        if (!flag)
            low = mid + 1;
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