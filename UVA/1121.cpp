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
int n , s ; 

void solve()
{
    vector<int>arr(n);
    for(int &i :arr)cin>>i;
    int l = 0 , r = -1 ;
    int ans =INT_MAX , sum = 0;
    while(l< n){
        while(r+1 <n && sum  < s ) 
            sum += arr[++r] ;
        if(sum >= s )ans =min(ans , r -l +1);       
        sum-=arr[l++];
    }
    if(ans==INT_MAX)ans = 0 ; 
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     //freopen("in" ,"r" ,stdin);
    while(cin >> n>>s ) solve();
    
    return 0 ; 
}