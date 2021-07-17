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
vector<bool>used ;
void dfs (vector<vector<int>>adj , int node ){
    if(used[node])
        return;
    used[node]=1 ;
    for(int next : adj[node]){
        dfs(adj, next);
    }
}
int t ; 
void solve()
{
    char limit ;
    cin>>limit ;
    int n = limit-'A';
    vector<vector<int>>adj(n+1); 
    used.assign(n+1 , 0 );
    string input ;
    getline(cin , input);
    while(getline(cin ,input) && input !=""){
        adj[input[0]-'A'].pb(input[1]-'A');
        adj[input[1]-'A'].pb(input[0]-'A');
    }
    int res =0 ; 
    for(int i =0 ;i <=n ;i++){
        if(!used[i]){
            res ++;
            dfs(adj , i ); 
        }
    }
    cout <<res<<"\n";
    if(t >0)cout <<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>t ;
    while(t--){
        solve();
    }
    return 0 ; 
}