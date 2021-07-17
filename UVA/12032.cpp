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

bool calc(vector<int>&arr , int k)
{
    for(int i =0 ;i < (int)sz(arr)-1 ;i++)
    {
        if(abs(arr[i+1] -arr[i])>k )return 0;
        if(abs(arr[i+1] -arr[i])==k)k--;
    }        
    return 1 ;
}
int k =1 ; 
void solve()
{
    int n ; cin>>n ;
    vector<int>arr (n+1);
    arr[0]= 0; 
    for(int i =1 ;i  <=n ;i++)cin>>arr[i];

    int l = 1 ,  r = 1e7 ;
    int mid ;
    int res =1 ; 
    while(l<=r )
    {
        mid = l + (r-l)/2;
        if(calc(arr , mid))
            res = mid , r = mid -1;
        else 
            l=mid+1 ;
    }
    printf("Case %d: %d\n", k++ , res );

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