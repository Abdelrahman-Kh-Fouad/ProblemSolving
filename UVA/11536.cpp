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
int tt =0 ;
typedef long long ll;
typedef unsigned long long ull;
void solve()
{
    int n ,m , k; cin>>n >>m >> k ;
    vector<int>arr(n);
    arr[0]=1, arr[1]=2 , arr[2] =3 ; 
    for(int i = 3 ;i <n ;i++) 
        arr[i]=(arr[i-1]+arr[i-2]+arr[i-3])%m +1;

    int l =0 , r = -1 , ans =INT_MAX;
    map<int ,int >num ;
    while (l<n )
    {
        while (r+1< n && sz(num)<k )
            if(arr[++r] <=k ) num[arr[r]]++ ;
        
        if( sz(num)==k )
            ans = min(ans , r-l+1);
        if(num.count(arr[l]))
        {
            if(num[arr[l]]==1)
            num.erase(arr[l]);
            else num[arr[l]] -=1;
        }
        l++ ;
    }
    cout<<"Case "<<++tt <<": ";
    if(ans ==INT_MAX)
        cout<<"sequence nai"<<endl;
    else
        cout<<ans<<endl;
    

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen64("in" ,"r" ,stdin);
    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}