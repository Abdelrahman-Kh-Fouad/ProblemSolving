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
int n ;
void solve()
{
    int l  ; cin>> l ; 
    vector<vector<int>>adj(n);
    while(l--)
    {
        int t , f ; cin>>t >>f ; 
        adj[t].pb(f);
        adj[f].pb(t);
    }
    queue<pair<int,bool>>q; 
    int used[n];
    memset(used , -1  ,sizeof used);
    q.push({0 , 0});
    used[0] = 0;
    bool f = 1 ;
    while (!q.empty())
    {
        pair<int,bool>cur = q.front();
        q.pop();
        for(int &i : adj[cur.ff])
        {
            if(used[i]==-1)
                q.push({i , !cur.ss}) , used[i] = !cur.ss;
            else 
                f &=(used[i] == !cur.ss );
        }
    }
     if(!f)
        cout<<"NOT BICOLORABLE."<<endl;
    else 
        cout<<"BICOLORABLE."<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>n && n!= 0 )
    {
        solve();
    }
    return 0 ; 
}