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
vector<int>arr ;  
void LIS (vector<int> &arr ,vector<int>&lis )
{
    vector<int>l(sz(arr));
    int limit = 0 ;
    for(int i =0 ; i < sz(arr) ; i++)
    {
        int ind = lower_bound(l.begin() , l.begin()+ limit ,arr[i] ) - l.begin();
        l[ind] = arr[i];
        if(ind == limit)limit++ ;
        lis[i]=ind+1 ;
    }
}
void solve()
{
    arr.assign(n , 0 );
    for(int i =0 ; i < n ;i++)cin>>arr[i];
    vector<int>bigger(n),smaller(n);
    LIS(arr , bigger);
    reverse(all(arr));
    LIS(arr , smaller);
    reverse (all(smaller));
    int res = 0 ; 
    for(int i =0 ;i < n ;i++)
        res = max(res , min(smaller [i] , bigger [i] ) );
    
    cout<< (res-1 )*2 +1<<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    while(cin >>n) 
    {
        solve();
    }
    return 0 ; 
}