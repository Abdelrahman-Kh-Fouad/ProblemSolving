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
    int n; cin>>n;
    double p[n];
    string tmp ; 
    for(int i =0 ;i <n ;i++)
        cin>>tmp >>p[i];
    sort(p , p+ n );
    reverse(p , p+n );
    double res =0;
    for(int i =0 ;i < n ;i++)
        res+=(i+1)*p[i];
    printf("%0.4f\n",res);

    return 0 ; 
}