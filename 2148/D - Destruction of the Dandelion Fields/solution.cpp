#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int arr[n];
        vector<long long int> even;
        vector<long long int> odd;
 
        long long int sum = 0;int flag = 0;
 
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
                even.push_back(arr[i]);
            else
            {
                odd.push_back(arr[i]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << sum << endl;
            continue;
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        for (int i = 0; i <even.size(); i++)
        {
            sum += even[i];
        }
        int x = (odd.size()) / 2;
        for (int i = x; i < odd.size(); i++)
        {
            sum += odd[i];
        }
 
        cout << sum << endl;
    }
 
    return 0;
}