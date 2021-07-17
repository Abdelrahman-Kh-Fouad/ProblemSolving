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
int tt ; 
pair<int ,int > memo[101];
pair<int,int>dp(vector<vector<int>>&adj  ,  int node )
{
    if(memo[node] != make_pair(-1 ,-1 ))
        return memo[node];
    pair<int,int> res ={node ,0 };
    for(int &i : adj[node])
    {
        pair<int ,int >tmp = dp(adj , i);
        if(tmp.ss+1 > res.ss )
            res.ss = tmp.ss+1 ,res.ff = tmp.ff ; 
        else if(tmp.ss+1 == res.ss && tmp.ff < res.ff)
            res.ss = tmp.ss+1 , res.ff = tmp.ff ;
    }
    return memo[node] = res ; 
}

// pair<int,int>res ={-1 ,-1 };
// void go(vector<vector<int>> &adj , int node ,int d =0  )
// {
//     if(d > res.ss )
//         res.ss = d , res.ff = node ; 
//     else if (res.ss== d && res.ff > node )
//         res.ff = node ;

//     for(int &i : adj[node])
//         go(adj, i , d+1 );
    
// }
void solve()
{   
    int start ; cin>>start; 
    int to ,from  ;
    vector<vector<int>>adj(n+1);
    while (cin>>from >>to && (from !=0 && to !=0 ))
        adj[from].pb(to);
    
    for(int i =0 ;i <= 100 ; i ++)
        memo[i]={-1 ,-1 };
    pair<int,int> res = dp(adj ,start );
    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++tt , start , res.ss , res.ff);
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>n && n!=0 )
    {
        solve();
    }
    return 0 ; 
}