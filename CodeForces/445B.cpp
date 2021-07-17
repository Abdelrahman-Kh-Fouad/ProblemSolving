#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+5 ;
struct DSU
{
    ll par[N] ,sz[N] , cnt;
    void init(int n )
    {
        iota(par , par +n  , 0);
        fill(sz ,sz+n , 1 );
        cnt = n ;
    }
    int find(int x )
    {
        if (par[x] == x )return x ;
        return par[x] = find(par[x]);
    }
    bool merge(int u ,int v )
    {
        u = find(u);
        v = find(v);
        if (u== v) 
            return false;
        
        if(sz[v] < sz[u])swap(u , v );
        par[u] = v ;
        sz[v] += sz[u];
	    sz[u] = 0;  
        return true;
    }
    

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ,t ;cin>>n >>t ;
    DSU dsu ;
    dsu.init(n);
    while(t--)
    {
        int u ,v ;
        cin>> u >>v ;
        dsu.merge(u-1 , v-1 );
    }
    ll res =0 ; 
    for(int i =0 ;i < n ;i++ )
        if(dsu.sz[i] != 0 )
            res += 1;
    cout << (1ll << n - res) <<endl;
    return 0 ; 
}
