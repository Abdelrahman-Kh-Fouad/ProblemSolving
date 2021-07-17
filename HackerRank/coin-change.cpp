#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
 
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.ff << ", " << p.ss << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    for(int i =0; i< sz(v) ; i++) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}
typedef long long ll;
typedef unsigned long long ull;
ll memo[100][500];
ll dp(vector<int>&coins , int n ,int ind =0  ,ll sum = 0 )
{
    if(sum > n|| ind > sz(coins) ) return 0 ;
    if(sum==n )return 1;
    ll &stat =memo[ind][sum];
    if(stat !=-1 )return stat ;
    ll res =0;
    for(ind ; ind < sz(coins) ;ind++ )res +=dp(coins , n , ind, sum+coins[ind]);
    return stat =res ;
}
ll getWays(int n , vector<int>&coins)
{
    memset(memo ,-1 , sizeof memo);
    return dp(coins ,n);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , m ; cin>>n >>m ;
    vector<int>arr(m);
    for(int &i :arr)cin>>i ;
    cout<<getWays(n , arr)<<endl;
    return 0 ; 
}