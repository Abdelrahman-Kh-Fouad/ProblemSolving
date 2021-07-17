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
    stringstream ss (s);
    vector<int> arr ; 
    int tmp ; 
    while(ss >>tmp )
        arr.pb(tmp);
    int mx =-1 ;
    for(int i = 0; i < sz(arr) -1  ;i++)
        for(int j = i+1 ; j<sz(arr) ;j++)
            mx= max(mx , __gcd(arr[i] ,arr[ j]));
        
    
    cout<<mx <<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    getline(cin ,s );
    while(t--)
    {
        solve();
    }
    return 0 ; 
}