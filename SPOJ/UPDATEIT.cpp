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



const int N = 10001; 
struct BIT{
    int tree[N];
    void init()
    {
        memset(tree , 0  ,sizeof tree );
    }
    void add(int pos , int val )
    {
        for(++pos ; pos <=N ; pos+=(pos & (~pos))) tree[pos -1 ]+=val;
    }
    int get(int pos)
    {
        int res =0 ;
        for(++pos ;pos ;pos -= (pos & (~pos))) res += tree[pos -1];
        return res;
    }
};



void solve()
{
    int n , u ; 
    cin>> n >> u ;
    vector<int>arr(n , 0 ) , ind(n+ 1 ,0 );
    while (u--)
    {
        int l ,r ,val ;
        cin >> l>> r >> val;
        ind[l] += val ; 
        ind[r+1] += -val ;
    }
    int q ; cin>> q;
    ll cur = 0 ;   
    for(int i =0 ;i  <n ;i ++ )
    {
        cur += ind[i];
        arr[i] =cur ; 
    }    
    while (q--)
    {
        int ind ; cin>> ind ;
        cout <<arr[ind]<<endl;
    }
    
     
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}