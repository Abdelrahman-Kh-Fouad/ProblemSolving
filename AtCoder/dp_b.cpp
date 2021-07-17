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

int n , k ; 
ll arr[(int)1e5 +1 ];
ll memo[(int)1e5 +1];
int dp(int ind )
{   
    ll &stat = memo[ind];
    if(stat !=-1)return stat ; 
    stat =  LONG_LONG_MAX;
    int cnt =0 ;
    for(int i =1 ;i  <=k;i++)
    {
        if(ind+i >=n )continue;
        stat =min(stat , dp(ind+ i )+ abs(arr[i+ind] - arr[ind])); 
        cnt ++;
    }
    if(cnt )return stat ;
    else return stat = 0; 

}
void solve()
{
    cin>>n >>k;
    for(int i =0 ;i<n ;i++)cin>>arr[i];
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