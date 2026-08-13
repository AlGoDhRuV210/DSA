#include <iostream>
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
        int sum=0;
        for (int i = 0; i < n; i++)
        {
           sum+=arr[i];
        }
        if(sum%3==0) cout<<"1 2";
        else cout <<"0 0";
        cout << endl;
    }
 
    return 0;
}