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
ll N ; 

void solve()
{   
    vector<ll>div;
    for(ll i =1 ; i* i <= N ;i++ )
    {
        if(N % i == 0 )
        {
            div.pb(i );
            if(i *i != N )
                div.pb(N /i );
        }
    }
    int res =0 ; 
    for(int i=0 ; i <sz(div) ;i++ )
    {
        for(int j= i ; j<sz(div) ;j++ )
        {
            if((((ll)div[i] *(ll) div[j])/ (ll)__gcd(div[i] , div[j] )) == N )
                res ++; 
        }
    }
    cout <<N<<" "<<res<<endl;
}
int main()  
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin>> N && N != 0 )
    {
        solve();
    }
    return 0 ; 
}