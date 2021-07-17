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

class segmantree {
private:
    int N ;
    vector<ll> arr,sTree , lazy ;
public :
    segmantree(vector<ll>in)
    {
        arr =in ; 
        N = in.size()-1 ;
        sTree.assign(N<<1, 0);
        build(1 ,1, N, (int)(floor(log2(N)) +1)%2  );

    }
    int left(int node ){return node <<1;}
    int right(int node ){return (node <<1) +1 ;}

    void build (int node  , int l , int r , bool cnt)
    {
        if(l== r )
            sTree[node]=arr[l] ;
        else 
        {
            int mid = l +r >> 1 ;
            build(left(node) , l , mid , cnt ^1 );
            build(right(node) , mid+1  , r , cnt ^1 );
            if(!cnt )
                sTree[node]= sTree[left(node)] | sTree[right(node)];
            else 
                sTree[node]= sTree[left(node)] ^ sTree[right(node)];
        }
    }
    void update_point(int ind , int val )
    {
        ind +=N-1 ;
        sTree[ind]=val;
        bool cnt = 0 ;
        while(ind >1 )
        {
            ind>>=1 ;
            if(!cnt)
                sTree[ind] = sTree[ind <<1] | sTree[(ind <<1) +1];
            else 
                sTree[ind] = sTree[ind <<1] ^ sTree[(ind <<1) +1];
            cnt ^= 1 ;
        }
    }
    int query(int i ,int j ){return query(1 , 1  ,N ,  i , j );}
    int query(int node ,int l ,int r , int i ,int j , bool cnt =0 )
    {
        if( i > r || j < l )return 0 ;
        if(l >= i && r <= j )return sTree[node];
        int mid = l + r >>1 ; 
        int q1 = query(left(node ) , l , mid , i ,j , cnt ^1 );
        int q2 = query(right(node ) , mid+1 ,r , i ,j ,cnt ^1) ;
        return (cnt ) ?(q1 ^ q2) : (q1 | q2)  ; 
    }

};

void solve()
{   
    int n ; cin>>n ; 
    int q ; cin>>q ; 
    int N = (1 << n) ;
    vector<ll>arr(N +1);
    for(int i =1 ;i  <=N ;i++)cin>>arr[i];
    segmantree sg(arr);
    while(q--)
    {
        int l , r ; 
        cin>> l >> r ;
        sg.update_point(l, r );
        cout<<sg.query(1 , N )<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0 ; 
}