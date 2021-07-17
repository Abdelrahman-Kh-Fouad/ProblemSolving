#include <bits/stdc++.h>
using namespace std ;
int main() {
    int n ;double v;cin>>n>>v;
    int arr[n] , b[n];
    for(int i =0 ;i < n ;i++)cin>>arr[i];
    for (int i =0 ;i < n ;i++)cin>>b[i];
    double res =INT_MAX;
    for (int i =0 ; i < n ;i++)
        res = min(res,((double)b[i]/arr[i]));
    double sum =0 ;
    for(int i =0 ;i < n ;i++)
        sum+=res*arr[i];
    cout<<min(v,sum);
    return 0;
}
