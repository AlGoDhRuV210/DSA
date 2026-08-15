#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[100000], ls[100000] = {0}, no;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            ls[arr[i] - 1]++;
        }
        sort(ls, ls + n);
        int s = n;
        int ans=s;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans,s-(n-i)*ls[i]);
        }
cout<<n-ans;
        cout << endl;
    }
 
    return 0;
}