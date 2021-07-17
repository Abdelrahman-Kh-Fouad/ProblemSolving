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
int memo[10001];
int go (vector<vector<int>>&adj  ,int par ,int node )
{
    int &stat = memo[node ];
    if(stat !=-1)return stat ;  
    int res =-1 ; 
    for(int i : adj[node ])
    {
        if(par != i )
            res =max (go(adj , node , i ) ,res );
    }
    return stat = res+1 ; 
}
void solve()
{
    int n ; cin>>n ; 
    vector<vector<int>>adj(n+1);
    
    for(int i = 0 ;i < n -1 ; i++ )
    {
        int  t , f ; cin>>t >>f ; 
        adj[t].pb(f);
        adj[f].pb(t);
    }
    memset(memo , -1 , sizeof memo );
    vector<int>arr;
    for(int i : adj[1])
        arr.pb(go(adj , 1 , i)+1 );
    arr.pb(0);
    
    sort(all(arr) , greater<int>());
    cout<<arr[0]+arr[1] <<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
        solve();
    
    return 0 ; 
}