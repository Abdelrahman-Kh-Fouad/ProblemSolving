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
void solve()
{
    int n ; cin>> n ;
    unordered_map<string ,string>from_to ;
    unordered_map<string ,int >inedge;
    for(int i =0 ;i  <n ;i++)
    {
        string from , to ; 
        cin>>from >>to ; 
        from_to[from] = to;
        inedge[to]++;
    }
    vector<pair<string ,string>>res ;
    for(auto i : from_to)
    {
        if(inedge.count(i.ff))continue;
        string from = i.ff ,to =i.ff; 
        while(from_to.count(to))to=from_to[to] ;
        res.pb(make_pair(from ,to));
    }
    cout<<sz(res)<<endl;
    for(auto i : res )cout<<i.ff <<" "<<i.ss<<endl;


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
    return 0 ; 
}