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
int memo[31];
int dp(int x )
{
    if(x==0)return 1 ;
    if(x==1)return 0 ;
    if(x==2)return 3 ;
    if(x==3)return 0 ;
    int &stat = memo[x];
    if(stat!=-1)return stat ;
    int res = 0;    
    res =4*dp(x-2) - dp(x-4);
    return stat = res ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >>n && n!=-1)
    {
        memset(memo , -1 ,sizeof memo);
        cout<< dp(n)<<endl;
    }
    return 0 ; 
}