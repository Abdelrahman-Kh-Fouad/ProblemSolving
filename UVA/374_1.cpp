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
ll b , p , m ;

ll power(ll b , ll p , ll m )
{   
    if(p ==0)return 1 ; 
    if(p % 2)return (b * power( b , p -1, m ) )%m;
    ll tmp = power ( b , p /2 , m ) ;
    return (tmp *tmp )% m ; 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin>> b >> p >> m )
    {
       cout<<  power(b , p , m )<<endl  ;
    }
    return 0 ; 
}