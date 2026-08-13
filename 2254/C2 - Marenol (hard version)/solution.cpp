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
    // vi a(n);
    // f(i,n) cin>>a[i];
    string a, b;
    cin >> a >> b;
 
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (n <= 2)
    {
        if (a != b)
            cout << "-1" << endl;
        return;
    }
    int move = 0;
 
    for (int i = 1; i < n; i++)
    {
        /* code */
        if (a[i] != a[i - 1])
        {
            move = 1;
            break;
        }
    }
    if (!move)
    {
        cout << "-1" << endl;
        return;
    }
    int one = 0, zero = 0;
    for (auto i : a)
    {
        if (i == '1')
            one++;
        else
            zero++;
    }
    int temp1 = one, temp2 = zero;
    for (auto i : b)
    {
        if (i == '1')
            one--;
        else
            zero--;
    }
    if (one != 0 || zero != 0)
    {
        cout << "-1" << endl;
        return;
    }
    one = temp1;
    zero = temp2;
 
    int evenone1 = 0, evenzero1 = 0;
    int evenone2 = 0, evenzero2 = 0;
 
    for (int i = 0; i < n; i += 2)
    {
        /* code */
        if (a[i] == '1')
            evenone1++;
        else
            evenzero1++;
        if (b[i] == '1')
            evenone2++;
        else
            evenzero2++;
    }
    if (evenone1 != evenone2 || evenzero1 != evenzero2)
    {
 
        cout << "-1" << endl;
        return;
    }
 
    // first even;
    int ans = 0;
 
    vi a1, b1, a0, b0;
    for (int i = 0; i < n; i += 2)
    {
        /* code */
        if (a[i] == '1')
            a0.push_back(i);
 
        if (b[i] == '1')
            b0.push_back(i);
    }
    for (int i = 1; i < n; i += 2)
    {
        /* code */
        if (a[i] == '1')
            a1.push_back(i);
 
        if (b[i] == '1')
            b1.push_back(i);
    }
 
    for (int i = 0; i < a0.size(); i++)
    {
        /* code */
        ans += (abs(a0[i] - b0[i])) / 2;
    }
    for (int i = 0; i < a1.size(); i++)
    {
        /* code */
        ans += (abs(a1[i] - b1[i])) / 2;
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