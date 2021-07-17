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

void solve()
{
    int f ,s ,g, up, down;
    cin>>f >>s >>g >>up>>down;
    int res =-1;
    vector<bool>used(f+1 , 0);
    queue <pair<int,int>>q ;
    q.push({s , 0 });
    used[s]=1;
    while (!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        if(cur.ff == g )
        {
            res = cur.ss ;
            break;
        }
        if(cur.ff +up <= f && !used[cur.ff +up])
            q.push({cur.ff +up , cur.ss+ 1 }) ,used[cur.ff+up]=1 ;
        if(cur.ff -down >=1 && !used[cur.ff -down])
            q.push({cur.ff -down , cur.ss+ 1 }),used[cur.ff-down]=1;
    }
    if(res==-1)
        cout<<"use the stairs"<<endl;
    else    
        cout<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0 ; 
}