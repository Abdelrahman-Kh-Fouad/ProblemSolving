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

string a, b ;
int memo[1001][1001];
int dp(int i =0  ,int j = 0)
{
    if(i==sz(a) && j==sz(b))return 0 ;
    int &stat =memo[i][j];
    if(stat!=-1)return stat; 
    if(i==sz(a)) return stat = (sz(b) - j )*30;
    if(j==sz(b)) return stat = (sz(a) - i )*15;
    if(a[i] ==b[j]) return  stat =dp(i+1 , j+1 );
    return stat = min(dp(i+1 , j )+15 , dp(i ,j+1 )+30);
} 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(getline(cin ,a ) && a!="#")
    {
        getline(cin , b);
        memset(memo ,-1 ,sizeof memo);
        cout<<dp()<<endl;
    }
    return 0 ; 
}