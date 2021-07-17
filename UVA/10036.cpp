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




int n , k ; 
int memo[10001][101];
int arr[10001];

bool dp(int ind   ,int res   )
{
    if(ind == n )
        return !res;
    int &stat = memo[ind][res];
    if(stat !=-1)return stat ; 
    return stat = dp(ind+1 , (((res + arr[ind]) % k)+k)%k)
    || dp(ind+1 , (((res - arr[ind]) % k)+k)%k ); 

}
void solve()
{
    cin>>n >>k;
    for(int i =0 ;i  <n ;i++)cin>>arr[i];
    memset(memo , -1 , sizeof memo);
    cout<<(dp(1 ,((arr[0]%k)+k )%k  ) ? "Divisible" : "Not divisible")<<endl;     
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