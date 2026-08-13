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
 
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
void solve()
{
    int n, m;
    cin >> n >> m;
    vi v(n + 1, 0);
    vi owner(n + 1, 0);
    while (m--)
    {
        char op;
        int x;
        cin >> op >> x;
 
        if (op == '+')
        {
 
            if (v[x] == 1)
                cout << "Already on" << endl;
            else
            {
                int flag = 0;
                int temp = x;
                for (int i = 2; i * i <= temp; i++)
                {
                    if (temp % i == 0)
                    {
                        if (owner[i] != 0)
                        {
                            cout << "Conflict with " << owner[i] << endl;
                            flag = 1;
                            break;
                        }
                        while (temp % i == 0)
                            temp = temp / i;
                    }
                }
                if (!flag && temp > 1 && owner[temp] != 0)
                {
                    cout << "Conflict with " << owner[temp] << endl;
                    flag = 1;
                }
                if (flag)
                    continue;
                v[x] = 1;
                temp = x;
                for (int i = 2; i * i <= temp; i++)
                {
                    if (temp % i == 0)
                    {
                        owner[i] = x;
                    }
                    while (temp % i == 0)
                        temp = temp / i;
                }
                if (temp > 1)
                    owner[temp] = x;
 
                cout << "Success" << endl;
            }
        }
        else
        {
            if (v[x] == 0)
                cout << "Already off" << endl;
            else
            {
                int temp = x;
                v[x] = 0;
                for (int i = 2; i * i <= temp; i++)
                {
                    if (temp % i == 0)
                    {
                        owner[i] = 0;
                    }
                    while (temp % i == 0)
                        temp = temp / i;
                }
                if (temp > 1)
                    owner[temp] = 0;
                cout << "Success" << endl;
            }
        }
    }
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}