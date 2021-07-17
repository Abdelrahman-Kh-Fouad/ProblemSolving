#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
vector<bool>used;
double go(vector<vector<int>>&adj , int node ,int l)
{
    if(used[node])return 0  ;
    used[node]=1;
    int cnt = 0 ;
    for(int &i : adj[node])
        cnt +=(!used[i]);
    if(!cnt)    
        return l ;
    double res = 0 ;
    for(auto &i :adj[node])
        res+= (1.0)/cnt * go(adj , i , l+1 );
    return res ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ; cin>>n ;
    used.assign(n+1 , 0 );
    vector<vector<int>>adj(n+1);
    int t ,f ;
    for(int i =0 ;i < n-1 ;i++)
        cin>>f >>t , adj[f].pb(t) , adj[t].pb(f);
    printf("%0.10f\n" , go(adj , 1 , 0));
    
    return 0 ; ;
}