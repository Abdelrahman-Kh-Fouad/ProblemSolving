#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;

ll MOD=10000007;
ll power(ll b , ll p , ll m )
{   
    if(p ==0)return 1 ; 
    if(p % 2)return (b * power( b , p -1, m ) )%m;
    ll tmp = power ( b , p /2 , m ) ;
    return (tmp *tmp )% m ; 
}

ull n , k ; 
void solve()
{
    cout << (2* power(n-1 , k ,MOD ) + power(n , k ,MOD) + 2*power(n-1 , n-1 , MOD) + power(n ,n , MOD))% MOD<<endl;    
}   
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    while(cin >>n >> k && (n || k) )
    {
        solve();
    }
    return 0 ; 
}