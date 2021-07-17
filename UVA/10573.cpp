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
string s ; 
void solve()
{
    getline(cin ,s );
    stringstream ss(s);

    vector<double>r(2 ,-1);
    int ind =0  ;
    while (ss>>r[ind++]);
    if( r[1] ==-1)
        r[0] /= 4 ,r[1] =r[0] ;

    double R =r[0]+r[1];
    cout<< fixed << setprecision(4) << ((double)2*acos(0)) * ((R*R) - (r[0]*r[0]) -(r[1]*r[1]))<<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;        getline(cin ,s );

    while(t--)
    {
        solve();
    }
    return 0 ; 
}