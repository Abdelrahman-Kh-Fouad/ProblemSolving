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
int n , m ; 
char arr[1001][1001];
ll memo[1001][1001];
ll dp(int x , int y )
{
    if(x >=n || y>=m )return (int)0;
    if(arr[x][y]!='.')return (int)0;
    if(x==n-1 && y==m-1 )return  1;
    ll &stat=memo[x][y];
    if(stat !=-1)return memo[x][y]; 
    return stat= (dp(x+1 ,y ) +dp(x, y+1)) % (ll)(1e9+ 7 );
}
void solve()
{
    cin>>n>>m;
    for(int i =0 ;i  <n ;i++)
        for(int j =0 ;j  <m ;j++)
            cin>>arr[i][j];
    memset(memo , -1 , sizeof memo);
    cout<<dp(0 ,0)<<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
   
    return 0 ; 
}