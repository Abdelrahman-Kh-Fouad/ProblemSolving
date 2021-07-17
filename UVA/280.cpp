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
int n ; 
typedef long long ll;
typedef unsigned long long ull;
void solve()
{
    vector<vector<int>>adj(n+1 );
    int start ;
    while(cin>> start && start != 0)
    {
        int to ;
        while(cin>> to && to !=0)
            adj[start].pb(to);
    }
    int k ; cin>> k ;
    for(int i =0 ;i < k ;i++)
    {
        int v ; cin>> v ;
        bool used[n+1]={0};
        queue<int>q ;
        for(int &i :adj[v])q.push(i); 
        while (!q.empty())
        {
            int cur= q.front();
            q.pop();
            used[cur] =1 ;
            for(int &i : adj[cur])
                if(!used[i]) q.push(i) , used[i]= 1 ;
        }

    
        vector<int>res ; 
        for(int i =1 ; i<=n ;i++)
            if(!used[i])res.pb(i);
        cout<<sz(res);
        for(int i =0 ;i < sz(res) ;i++)
            cout<<" "<<res[i];
        cout<<endl;
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >>n && n!=0)
    {
        solve();
    }
    return 0 ; 
}