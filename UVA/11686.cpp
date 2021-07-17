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
int n , m ; 

void solve()
{
    vector<vector<int>>adj(n , vector<int>());
    vector<int>in(n , 0);
    for(int i =0 ;i < m ;i++){
        int u , v ; cin>> u >>v  ;
        adj[u-1].pb(v-1);
        in[v-1] ++ ;
    }
    queue<int>q ; 
    for(int i =0 ;i <n ;i++)
        if(!in[i])q.push(i);
    vector<int>res ;
    bool f =1 ;  
    while(q.size()){
        int cur = q.front();
        q.pop();
        res.pb(cur);
        for(int i : adj[cur]){
            in[i]--;
            if(!in[i])
                q.push(i);
            f &= in[i]>=0;
        }
    }
    if(f && sz(res) ==n ){
        for(int i: res)
            cout<< i +1 <<endl;
    }
    else {
        cout <<"IMPOSSIBLE"<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >>n >>m && (n && m) )
    {
        solve();
    }
    return 0 ; 
}