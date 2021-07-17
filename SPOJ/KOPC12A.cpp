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
ull calc (vector<int>&c , vector<int>&h , int k )
{
    ull res = 0; 
    for(int i = 0 ; i < (int)sz(h) ; i++)
        res +=(abs(h[i] - k) * (ll)c[i]);
    
    return res ;
}
ull ts (vector<int>&c , vector<int>&h)
{
    ll l =1 , r = 10000 ;
    ll m1 ,m2 ;
    while (l<r )
    {
        m1 = l + (r-l )/3;
        m2 = r - (r-l )/3;
        ull f1 = calc(c ,h ,m1);
        ull f2 = calc(c ,h, m2);
        if(f1 < f2)
            r= m2-1;
        else 
            l =m1+1 ;
    }
    return calc(c , h , l);
    
}
void solve()
{
    int n ;cin>>n; 
    vector<int>h(n);
    for(int i =0 ;i  <n ;i++)cin>>h[i];
    vector<int>c(n);
    for(int i =0 ;i  <n ;i++)cin>>c[i];
    cout<<ts(c , h )<<endl;;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}