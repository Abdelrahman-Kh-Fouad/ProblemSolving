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
int k =0 ;
void solve()
{
    int n ;cin >> n ;
    vector<int>a (n), b (n);
    for(int i =0 ;i <n ;i++)cin>>a[i] ;
    for(int i =0 ;i <n ;i++)cin>>b[i] ;
    sort(all(b));
    sort(all(a) ,greater<int>());
    ll res =0 ; 
    for(int i =0 ;i <n ;i++)
        res+=(ll)a[i]*b[i];
    cout<<"Case #"<<++k<<": "<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r" , stdin);
    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}