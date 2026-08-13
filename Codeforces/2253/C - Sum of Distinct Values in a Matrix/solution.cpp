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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
 
    vector<int> a(x);
    for (int i = 0; i < x; ++i)
    {
        cin >> a[i];
    }
 
    vector<int> b(y);
    for (int j = 0; j < y; ++j)
    {
        cin >> b[j];
    }
 
    vector<int> onlyina, onlyinb, both;
 
    int i = 0, j = 0;
    while (i < x && j < y)
    {
        if (a[i] < b[j])
        {
            onlyina.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j])
        {
            onlyinb.push_back(b[j]);
            j++;
        }
        else
        {
            // a[i] == b[j]
            both.push_back(a[i]);
            i++;
            j++;
        }
    }
 
    while (i < x)
    {
        onlyina.push_back(a[i]);
        i++;
    }
 
    while (j < y)
    {
        onlyinb.push_back(b[j]);
        j++;
    }
 
    reverse(onlyina.begin(), onlyina.end());
    reverse(onlyinb.begin(), onlyinb.end());
    reverse(both.begin(), both.end());
 
    if (onlyina.size() > n)
    {
        onlyina.resize(n);
    }
 
    if (onlyinb.size() > m)
    {
        onlyinb.resize(m);
    }
 
    vector<int> final_elements;
    final_elements.insert(final_elements.end(), onlyina.begin(), onlyina.end());
    final_elements.insert(final_elements.end(), onlyinb.begin(), onlyinb.end());
    final_elements.insert(final_elements.end(), both.begin(), both.end());
 
    sort(final_elements.begin(), final_elements.end(), greater<int>());
 
    long long max_cost = 0;
    int elements_to_take = min((int)final_elements.size(), n + m - 1);
 
    for (int k = 0; k < elements_to_take; ++k)
    {
        max_cost += final_elements[k];
    }
 
    cout << max_cost << "
";
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