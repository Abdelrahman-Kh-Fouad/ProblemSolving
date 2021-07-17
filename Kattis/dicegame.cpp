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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll gunnar = 0 , emma = 0 ;
    ll tmp ; 
    for(int i =0 ;i  <4 ;i++)cin>>tmp , gunnar+=tmp  ;
    for(int i =0 ;i  <4 ;i++)cin>>tmp , emma+=tmp  ;
    if(gunnar > emma)
        cout<<"Gunnar"<<endl;
    else if ( gunnar< emma)
        cout<<"Emma"<<endl;
    else 
        cout<<"Tie"<<endl;;
    return 0 ; 
}