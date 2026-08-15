#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, int> fre;
        vector<int> v(n);
        for (int i=0;i<n;i++)
        {
            cin >> v[i];
            fre[v[i]]++;
        }
        bool pos = true;
        for (auto &x : v)
        {
            if (fre[x] % k != 0)
                pos = false;
        }
        if (!pos)
        {
            cout << "0" << endl;
            continue;
        }
        map<int, int> mp;
        int r = 0;
        long long ans = 0;
        for (int l = 0; l < n; l++)
        {
            while (r < n)
            {
                if (mp[v[r]] < fre[v[r]] / k)
                {mp[v[r]]++;
                    r++;
                }
                else break;
            }
            ans+=r-l;
            mp[v[l]]--;
        }
 
        cout <<ans<< endl;
    }
 
    return 0;
}