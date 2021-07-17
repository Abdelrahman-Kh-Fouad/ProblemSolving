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
bool  calc (ll count ,ll rb , ll rs , ll rc ,ll nb , ll ns ,ll nc , ll pb , ll ps ,ll pc , ll r )
{

    rb = count * rb , rs = count *rs ,rc =  count *rc;
    if (rb > nb )
        r -=(rb - nb )*pb;
    if (rs > ns )
        r -=(rs - ns )*ps;
    if (rc > nc )
        r -=(rc - nc )*pc;
    return r >= 0 ;  

}
void solve()
{   
    string s ; cin>>s ; 
    ll nb , ns , nc ; 
    cin>>nb >> ns >>nc ; 
    ll pb , ps , pc ; 
    cin>>pb >> ps >> pc ; 
    ull r ; cin>>r ; 
    map<char, int>mp ; 
    mp['B']= 0 ; 
    mp['S']= 0 ; 
    mp['C']= 0 ; 

    for(auto i : s )mp[i]++ ;
    int rb = mp['B'] ,rs = mp['S'] ,rc = mp['C'] ;

    ull l = 0 , h=(ull) 1e13 ;
    ll mid ;
    ll res =-1 ;
    while(l <= h )
    {
        mid = l + (h- l )/2 ; 
        if(calc(mid , rb , rs , rc , nb , ns , nc ,pb , ps , pc , r  ))
            res = mid , l =mid+1  ;
        else 
            h=  mid-1 ;
    }
    cout<<res  <<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0 ; 
}