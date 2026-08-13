#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int avg = arr[0];
        for (int i = 0; i < n-1; i++)
        {
            if (avg < arr[i +1])
                avg = arr[i+1];
        }
        cout << avg << endl;
    }
 
    return 0;
}