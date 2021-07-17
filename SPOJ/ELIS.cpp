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
void solve()
{
    int  n ; cin >> n; 
    vector<int>arr(n);
    vector<int>cnt(21, 0 );
    for(int i =0 ;i < n ;i++)
        cin>>arr[i];

    vector<int>lis(n,1);
    for(int i =1 ; i < n ; i++)
    {
        for(int j =i-1 ; j >=0 ; j--)
        {
            if(arr[i] > arr[j] )
                lis[i] = max(lis[j]+1 , lis[i] );
        }
    }
    cout<< *max_element(all(lis))<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0 ; 
}