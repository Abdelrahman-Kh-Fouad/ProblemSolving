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
ll memo[11][11];
ll dp(vector<pair<int,int>>&mat , int i ,int j )
{
    if(i ==j)return 0;
    ll &stat =memo[i][j];
    if(stat!=-1)return stat;
    ll res =INT_MAX;
    for(int k = i ;k<j ;k++)
        res = min(res , dp(mat , i ,k ) +dp(mat ,k+1 , j)+mat[i].ff * mat[j].ss * mat[k].ss);
    return stat =res ;
} 
int cnt ;
void print(vector<pair<int,int>>&mat , int i ,int j )
{
    if(i ==j)
    {
        cout<< "A"<<++cnt;
        return ;
    }
    ll res =dp(mat ,i ,j );
    for(int k = i ;k<j ;k++)
        if(dp(mat , i ,k ) +dp(mat ,k+1 , j)+mat[i].ff * mat[j].ss * mat[k].ss == res)
        {
            
            if(k -i >=1)cout<<"(";
            print(mat , i , k );
            if(k -i >=1)cout<<")";
            cout<<" x ";
            if(j- (k+1) >=1) cout<<"(";
            print(mat , k+1 , j );
            if(j- (k+1) >=1) cout<<")";
            break;
        }
    
} 
int t =1 ;
void solve()
{
    vector<pair<int,int>>mat(n);
    for(int i =0 ;i < n ;i++) cin>>mat[i].ff >>mat[i].ss;
    memset(memo ,-1 ,sizeof memo);
    dp(mat , 0 ,n-1);

    cout<<"Case "<<t++<<": (";
    print(mat , 0 , n-1);
    cout<<")";
    cnt = 0 ;
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>> n && n!=0)
    {
        solve();
    }
    return 0 ; 
}