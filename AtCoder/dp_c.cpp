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




int n ;
int arr[3][(int)1e5 +1 ];
int memo[3][(int)1e5 +1];
int dp(int s , int ind )
{
    if(ind == n )return 0;
    int &stat = memo[s][ind];
    if(stat !=-1)return stat ;
    stat = 0 ;  
    for(int i = 0 ;i < 3 ;i++)
    if(i == s )continue;
    else stat = max(stat , dp(i , ind+1 ) + arr[i][ind]);
    return stat ;
}
void solve()
{
    cin>>n ;
    memset(memo , -1 ,sizeof memo);
    for(int i =0 ;i  <n ;i++)
        cin>>arr[0][i]>>arr[1][i]>>arr[2][i];
    cout<<max ({dp(0 ,0 ) ,dp(1, 0) ,dp( 2 , 0)})<<endl;;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0 ;
}