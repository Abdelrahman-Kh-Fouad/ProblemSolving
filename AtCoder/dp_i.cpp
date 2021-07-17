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





double memo[3000][3000];
int n ;
double p[3000];
double dp(int head=0 , int ind =0)
{
    if(ind == n )
       return head >= ceil(n /(float)2)  ;
    
    double &stat = memo[head][ind];
    if(stat !=-1)
        return stat ;
    stat = dp(head +1  , ind+1 ) * (p[ind]) + dp( head  , ind+1 ) *(1-p[ind]);
    return stat ;
}
void solve()
{
    cin>>n ; 
    for(int i =0 ; i <n ;i++)cin>>p[i];
    for(int i =0 ;i <3000 ;i++)for(int j= 0 ;j < 3000 ;j++)memo[i][j]=-1;  
    printf ("%0.9f\n" , dp());
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    solve();
  
    return 0 ; 
}