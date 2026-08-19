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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    if (k % 2 == 0)
    {
        vector<vi> v(k / 2, vector<int>(26, 0));
 
        // map<char, int> mpp;
        // first segment , second , ......
        for (int j = 0; j <= n - k; j += k)
        {
            for (int h = 0; h <= (k / 2) - 1; h++)
            {
                v[h][s[j + h] - 'a']++;
                // mpp[s[j + h]]++;
                v[h][s[j + k - (h + 1)] - 'a']++;
                // mpp[s[j + k - (h + 1)]]++;
            }
        }
        for (auto i : v)
        {
            ans += 2 * (n / k) - *max_element(all(i));
        }
    }
    else
    {
        vector<vi> v(k / 2 + 1, vector<int>(26, 0));
 
        // map<char, int> mpp;
        // first segment , second , ......
        for (int j = 0; j <= n - k; j += k)
        {
            for (int h = 0; h <= (k / 2) - 1; h++)
            {
                v[h][s[j + h] - 'a']++;
 
                v[h][s[j + k - (h + 1)] - 'a']++;
            }
            v[k / 2][s[j + k / 2] - 'a']++;
        }
 
        for (int i = 0; i < k / 2; i++)
 
        {
 
            ans += 2 * (n / k) - *max_element(all(v[i]));
        }
 
        ans += (n / k) - *max_element(all(v[k / 2]));
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