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
ll calc( vector<int> &a , vector<int> &b , int k )
{
    ll res =0 ; 
    for(auto &i : a )if(i <k)res += abs(i-k);
    for(auto &i : b )if(i >k)res += abs(i-k);
    return res ;
}
ll ts (vector<int>&a , vector<int> &b )
{
    ll l = 0 ,  r =1e9 ; 
    ll m1 , m2 ; 
    while(l < r )
    {
        m1 = l + (r-l)/3 ; 
        m2 = r - (r-l)/3 ; 
        ll f1  = calc(a , b ,m1 );
        ll f2  = calc(a , b ,m2 );
        if(f1 >f2 )
            l = m1 +1 ;
        else 
            r = m2 -1 ;
    } 
    return calc (a ,b , l) ; 
}
void solve()
{
    int n ,m ;cin>>n >>m ; 
    vector<int>a (n), b(m);
    for(int i =0 ;i  <n ;i++)cin>>a[i];
    for(int i =0 ;i  <m ;i++)cin>>b[i];
    // if(*min_element(all(a)) > *max_element(all(b)))
    //     cout<<0<<endl;
    // else 
        cout<<ts(a , b )<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

        solve();
    
    return 0 ; 
}