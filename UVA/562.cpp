#include<bits/stdc++.h>
using namespace std ;
int memo [150][50050]; 
int dp (vector<int> & arr , int &sum , int now =0 , int ind =0  )
{
    if(ind == arr.size())
        return  abs(now - (sum - now));
    int &stat = memo[ind][now];
    if(stat !=-1 )
        return stat ; 
    return stat = min ({dp(arr , sum ,now + arr[ind] , ind+1 ) ,dp(arr , sum ,now , ind+1 )});
}
 int main ()
 {
     int t ; cin>>t ; 
    while(t--)
    {
        memset(memo , -1 , sizeof memo);
        int n ; cin>>n ; 
        vector<int>arr(n);
        int sum = 0 ;
        for(int i =0 ;i < n ;i++)cin>>arr[i] ,sum+=arr[i];
        // sort(arr.begin() ,arr.end());
        // int l = 0 , r = arr.size()-1;
        // int a =0  , b=0 ; 
        // while(l<=r)
        // {   
        //     if(a < b )a+=arr[l++];
        //     else b += arr[r--];
        // }
        // cout<<abs(a - b)<<endl; 
        cout<<dp(arr ,sum )<<endl;
    }
}