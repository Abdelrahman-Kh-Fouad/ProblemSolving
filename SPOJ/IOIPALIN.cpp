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
int  n ;string s ; 
int memo [5001][5001];
int dp(int i ,int j )
{
    if( i > j )
        return 0 ;
    int &stat = memo[i][j];
    if(stat !=-1)return stat ;
    int ch3 = INT_MAX;  
    if(s[i] ==s[j])
        ch3 = dp(i+1 , j-1 );
    int ch1 = dp(i , j-1  )+1 ; 
    int ch2 = dp(i+1 , j  )+1 ;
    return stat = min ({ch1 ,ch2 ,ch3 });
}
void solve()
{
    cin>>n ;
    getline(cin ,s );
    getline(cin ,s );
    memset(memo , -1 , sizeof memo);
    cout <<dp(0 , n-1)<<endl;;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
    return 0 ; 
}