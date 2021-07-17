#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll power(ll b , ll p , ll m )
{   
    if(p ==0)return 1 ; 
    if(p % 2)return (b * power( b , p -1, m ) )%m;
    ll tmp = power ( b , p /2 , m ) ;
    return (tmp *tmp )% m ; 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    while(t--)
    {
        ll n , m ; 
        cin>>n>> m;
        cout<<power(n , m  , 10)<<endl;
    }
    return 0 ; 
}