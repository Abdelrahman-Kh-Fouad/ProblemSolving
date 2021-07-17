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
ll memo[1001][22][80];
int ox , ne ;

ll dp(vector<pair<int,int>>&v ,vector<int>&w , int ind =0,int oxegen=0 , int netro=0 )
{
    if(oxegen >= ox )oxegen = ox ; 
    if(netro >= ne )netro = ne ; 
    if(ind == sz(v))
        return (oxegen == ox && netro ==ne )? 0 :INT_MAX; 

    ll &stat = memo[ind][oxegen][netro];
    if(stat !=-1)return stat ;
    return stat = min (dp(v , w , ind+1 , oxegen , netro) , dp(v ,w  ,ind+1 , oxegen + v[ind].ff ,netro +v[ind].ss ) + w[ind]);
}
void solve()
{
    cin>> ox >> ne ;
    int n ; cin>>n ;
    vector<pair<int,int>>v(n);
    vector<int>w(n);
    for(int i =0 ;i < n ;i++)
        cin>>v[i].ff >>v[i].ss>>w[i];
    memset(memo , -1 ,sizeof memo);
    cout<<dp(v ,w )<<endl;

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