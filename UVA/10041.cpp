#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t ; cin>>t;
    while (t--)
    {
        int n ;cin>>n;
        int arr[n];
        for (int i =0 ;i < n ;i++) cin>>arr[i];
        int res =INT_MAX;
        for (int i =0 ;i <n ;i++)
        {
            int sum= 0 ;
            for (int j =0 ; j< n ; j++)
                sum+=(j==i)?0: abs(arr[i]-arr[j]);
            res=min(sum,res);
        }
        cout<<res<<endl;

    }
    return 0;
}
