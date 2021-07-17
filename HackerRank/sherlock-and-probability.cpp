#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;

void solve()
{
    int n ,  k ;cin>>n>>k ; 
    string s ; cin>>s ;
    vector<ll>sum(n+1 , 0);
    for(int  i  =1 ;  i <= n ;i++ )
        sum[i]+= (s[i-1] == '1') +sum[i-1];
    
    ll res = 0 ;
    for(int i =1 ; i <=n ;i++)
    {
        int end = min( n, i+ k); 
        int start = max ( i - k  ,1 );
        res+=(s[i-1] =='1')?  sum[end] - sum[start-1]   : 0 ;
    }
    ll tt = __gcd((ll)res , (ll)n*n);
    if(!res )
        puts("0/1");
    else
        printf("%lld/%lld\n" , res /tt , ((ll)n*n) /tt);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}