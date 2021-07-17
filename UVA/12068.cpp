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
int k =1 ; 
void solve()
{
    ll n ; cin>>n ; 
    ll arr[n];
    for(int i = 0 ;i  < n ;i++)cin>>arr[i];
    ll up =1 , down  =arr[0];
    for(int i =1 ; i < n ;i++)
    {
        up = up *arr[i]  + down;
        down = down *arr[i];
    }
    int tmp = __gcd(up , down );
    up /=tmp , down /= tmp ; 
    down *= n ;
    tmp = __gcd(down , up);
    
    cout<<"Case " <<k++<<": " <<down/tmp <<"/"<< up/tmp<<endl ;
    
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