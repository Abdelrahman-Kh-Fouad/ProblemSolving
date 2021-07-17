#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;
int k ; 
vector<int> w, v ;
ll memo[99][10001];  
ll dp(int ind =0, int weight =0 )
{
    if(weight > k ) return -1e6;
    if(ind == sz(v)) return 0 ; 
    ll &stat =memo[ind][weight];
    if(stat !=-1)return stat ; 
    return stat =max(dp(ind+1 , weight+ w[ind])+ v[ind], dp(ind +1 ,weight)); 
}
void solve()
{
    int  m  ; cin>>k >>m ;
    v.assign(m,0);
    w.assign(m,0);
    vector<pair<int,int>>arr (m);
    for(int i =0 ;i < m ;i++)   
        cin>>w[i]>>v[i];
    memset(memo , -1 ,sizeof memo);
    cout<<"Hey stupid robber, you can get "<<dp()<<"."<<endl;
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