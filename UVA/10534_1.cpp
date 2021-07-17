#include<bits/stdc++.h>
using namespace std ;
int n ; 
int arr[100000];

void lis(vector<int>&res)
{
    vector<int>l(n,INT_MAX); 
    int cnt1 =0; 
    for(int i =0 ;i < n ;i++)
    {
        int ind =lower_bound(l.begin() , l.end() , arr[i] ) -l.begin();
        l[ind]=arr[i];
        res[i] =ind+1;
    }
}
int main()
{
    while(cin>>n)
    {
        for(int i =0 ;i <n ;i++)cin>>arr[i];
        vector<int>pos(n) , neg(n);
        lis(pos);
        reverse(arr , arr+n);
        lis(neg);
        reverse(neg.begin() , neg.end());
        int res =0;
        for(int i =0 ;i<n ;i++)
            res = max( res , 2 * ( min( pos[i] , neg[i] ))-1 );
        cout<<res<<endl;
        
    }
    return 0 ;
}