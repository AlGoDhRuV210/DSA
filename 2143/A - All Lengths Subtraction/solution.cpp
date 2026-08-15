#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define lli long long int
 
void solve()
{
    int n;
    cin >> n;
    int index = 0;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (p[index] < p[i])
            index = i;
    }
    int l = index, r = index;
    int next_smaller_element = n - 1;
    bool flag;
    while (next_smaller_element > 0)
    {
        flag = false;
        if (l - 1 >= 0 && p[l - 1] == next_smaller_element)
        {
            l--;
            flag = true;
        }
        else if (r + 1 < n && p[r + 1] == next_smaller_element)
        {
            r++;
            flag = true;
        }
        if (flag == false)
        {
            cout << "NO" << endl;
            return;
        }
        next_smaller_element--;
    }
    cout << "YES" << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}