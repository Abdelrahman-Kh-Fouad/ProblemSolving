#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

class DSU {
public : 
    vector<int>parentArr;
public :
    DSU(int n ){
        this->parentArr.assign(n , -1 );
        for(int i =0 ;i < n ;i++)
            parentArr[i]= i ; 
    }
    int parent(int x ){return parentArr[x] ==x ? x : parentArr[x] = parent(parentArr[x]);}
    bool is_same(int x ,int y ){return parent(x ) == parent(y);}
    void merge(int x ,int y ){
        if(!is_same(x , y )){
            x = parent(x);
            y = parent(y);
            if(rand()&1) 
                swap(x ,y );    
            parentArr[y] =x;  
        }
    }
};
class Edge{
public :
    int u , v ;
    ull w;
public :
    Edge():u(0) ,v(0),  w(0){}
};
void solve()
{
    int n ,  m ;cin>>n >>m ;
    vector<Edge>edges(m,Edge());
    for(int i =0 ;i < m ;i++){
        cin>>edges[i].u >> edges[i].v >> edges[i].w ;
        edges[i].u--;
        edges[i].v--;
    }
    sort(all(edges) , [&](Edge &x , Edge &y ){
        return x.w > y. w;
    });
    DSU ds(n);
    int ind =0 ; 
    ull res =LONG_LONG_MAX;
    while(!ds.is_same(0, n-1 ) && ind < m){
        Edge cur = edges[ind++];
        if(!ds.is_same(cur.u , cur.v )){
            res =min(res , cur.w);
            ds.merge(cur.u , cur.v);
        }
    }

    if(ds.is_same(0 , n-1 ) )
        cout << res <<endl;
    else 
        cout <<-1<<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    while(t--){
        solve();
    }
    return 0 ; 
}