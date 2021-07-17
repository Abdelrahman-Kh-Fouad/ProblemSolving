#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n ; 
    while(cin >>n && n >= 0 )
    {
        cout<< ull(n)*(n+1)/2 +1 <<endl;
    }
    return 0 ; 
}