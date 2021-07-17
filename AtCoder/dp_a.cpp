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
ll arr[(int)1e5 +1 ];
int n ; 
ll memo[(int)1e5 +1];
ll dp(int ind )
{
    ll &stat = memo[ind];
    if(stat !=-1)return stat ;
    if(ind +1 >= n )
        return stat = 0 ;
    stat =INT_MAX;
    if(ind+1 < n )stat =min(stat , dp(ind+1 )+abs(arr[ind+1] -arr[ind]));
    if(ind+2 < n )stat =min(stat , dp(ind+2 )+abs(arr[ind+2] -arr[ind]));
    return stat ;
}
void solve()
{
    cin>>n ; 
    for(int i =0 ;i  <n ;i++)cin>>arr[i];
    memset(memo , -1 , sizeof memo);
    cout<<dp(0)<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
    return 0 ; 
}