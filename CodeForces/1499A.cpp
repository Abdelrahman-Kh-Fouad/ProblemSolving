#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;
void solve()
{
    int n ,k1 , k2 ; cin>>n >> k1 >>k2 ;
    int w , b ; cin>>w >>b ;
    int br1 =n - k1  ;
    int br2 =n - k2  ;
    if( min(k1 ,k2)  + abs(k1 -k2 )/2  >=w && min(br1 ,br2) + abs(br1 -br2 )/2  >=b )
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;

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