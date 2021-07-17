#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) ll((x).size())
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

class segmantree {
public:
    ll N ;
    vector<ll> arr,sTree , lazy ;
public :
    segmantree(vector<ll>&in)
    {
        arr =in ; 
        N = in.size()-1 ;
        sTree.assign(N<<1, (ll)(ll)1e18);
        lazy.assign(N<<1, 0 );
        build(1 ,1, N );
    }
    ll left(ll node ){return node <<1;}
    ll right(ll node ){return (node <<1) +1 ;}
    void build (ll node  , ll l , ll r )
    {
        if(l== r )
            sTree[node]=arr[l];
        else 
        {
            ll mid = l +r >> 1 ;
            build(left(node) , l , mid );
            build(right(node) , mid+1  , r );
            sTree[node]= min (sTree[left(node)] ,sTree[right(node)]);
        }
    }
    void update_range(ll i, ll j ,ll val){update_range(1 , 1 , N , i ,j , val);}
    void update_range(ll node ,ll l ,ll r , ll i ,ll j , ll val)
    {
        if(i > r || j < l)return;
        if(l >= i && r <=j)
            sTree[node]+= val , lazy[node]+=val;
        else
        {
            ll mid = l + r >> 1 ;
            progragate(node , l , mid , r );
            update_range(left(node) , l ,mid , i ,j , val);
            update_range(right(node) , mid+1  ,r , i ,j , val);
            sTree[node]=min (sTree[left(node)] , sTree[right(node)]);
        } 
    }
    void progragate(ll  node , ll l , ll mid ,ll r )
    {
        lazy[left(node)]+=lazy[node];
        lazy[right(node)]+=lazy[node];
        sTree[left(node)]+= lazy[node] ;
        sTree[right(node)]+= lazy[node] ;
        lazy[node]= 0 ;
    }
    ll query(ll i ,ll j ){return query(1 , 1  ,N ,  i , j );}
    ll query(ll node ,ll l ,ll r , ll i ,ll j)
    {
        if( i > r || j < l )return (ll)1e18;
        if(l >= i && r <= j )return sTree[node];
        ll mid = l + r >>1 ; 
        progragate(node , l, mid , r );
        ll q1 = query(left(node ) , l , mid , i ,j );
        ll q2 = query(right(node ) , mid+1 ,r , i ,j );
        return min(q1 , q2) ; 
    }

};

void solve()
{
    ll n ; cin>>n ; 
    ll N = 1 ; 
    while(N < n )
        N *=2 ; 
    vector<ll>arr(N+1, (ll)1e18);
    for(ll i =1;i  <=n ;i++)cin>>arr[i];
    segmantree sg (arr);
    ll q ; cin>> q ;
    string s ; 
    getline(cin , s );

    while(q--)
    {
        getline(cin ,s );
        stringstream ss (s);
        ll l ,r ;  ss >> l >>r ;
        l++ ,r++;
        ll tar =-2 ; bool ff =0 ;
        if(ss>>tar)ff = 1 ;
        if(ff)
        {
            if(l > r )
                sg.update_range(l ,N , tar) , sg.update_range(1 , r ,tar);
            else 
                sg.update_range(l ,r , tar);   
        }
        else 
        {
            if(l<=r )
                cout<<sg.query(l ,r )<<endl;
            else
                 cout<<min(sg.query(l ,N ) , sg.query(1 , r ))<<endl;;
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0 ; 
}