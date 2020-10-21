#include <bits/stdc++.h>
using namespace std ;
int left (vector<int  >&arr  ,int target )
{
    int l =0 , r = arr.size()-1 ;
    int mid =-1 ;
    int res=-1;
    while (l<=r )
    {
        mid=l+(r-l)/2;
        if (arr[mid] < target)
            res = mid, l =mid+1;
        else
            r=mid-1;
    }
    return res;
}
int right (vector<int> &arr , int target)
{
    int l=0 , r = arr.size()-1 ;
    int mid =-1 ;
    int res =-1 ;
    while (l<=r )
    {
        mid=l+(r-l)/2;
        if(target < arr[mid]  )
            res =mid ,  r =mid-1 ;
        else
            l=mid+1;
    }
    return res ;
}
int main() {
    int n ; cin>>n ;
    vector<int> ladies(n);
    for (int i=0; i<n;i++)cin>>ladies[i];
    int q ;cin>>q;
    vector<int> me(q);
    for (int  i =0 ;i < q ;i++)cin>>me[i];
    for (int i =0 ;i < q  ;i++)
    {
        long long  l = left(ladies  ,me[i]) ;
        long long  r = right(ladies  ,me[i]);
        if (l==-1 && r !=-1 )
            cout<<'X'<<" "<<ladies[r]<<endl;
        else if (l!=-1 && r==-1)
            cout<<ladies[l]<<" "<<'X'<<endl;
        else if (l== -1 && r==-1 )
            cout<<"X X"<<endl;
        else
            cout<<ladies[l]<<" "<<ladies[r] <<endl;
    }
    return 0;
}
