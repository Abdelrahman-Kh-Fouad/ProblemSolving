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

void babageDiffrenceEngine(vector<vector<int>> &def, int m) {
    while (def.back().size() > 1) {
        vector<int> n, &p = def.back();
        for (int i = 0; i < p.size() - 1; ++i) {
            n.emplace_back(p[i + 1] - p[i]);
        }
        def.emplace_back(n);
    }
    def.back().resize(m + 1, def.back().back());
    for (int i = def.size() - 1, j = 1; i > 0; --i, j++) {
        vector<int> &cur = def[i], &prv = def[i - 1];
        for (int k = 0; k < m; ++k) {
            prv.emplace_back(cur[k + j] + prv[k + j]);
        }
    }
}
void solve()
{
    int n , k ; cin>>n >>k ;
    vector<vector<int>>engine;
    vector<int>arr(n);
    for(int &i : arr) cin>> i ;
    engine.pb(arr);
    babageDiffrenceEngine(engine , k);
    for(int i = n ;i < sz(engine.front()) ;i++)
        cout<<engine.front()[i]<<" ";
    cout<<endl;


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