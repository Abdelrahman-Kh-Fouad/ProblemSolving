#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;


double p,q,r,s,t,u;

double f(double x) {
	return (p/exp(x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}
void solve( )
{
    double l = 0.0, r = 1.0;
    if (f(l) * f(r) > 0 || (!p && !q && !r && !s && !t && !u)) {
        cout << "No solution" << endl;
        return;
    }
    while (r-l >.00000001) {
        double mid = (l+r)/2;
        if (f(mid) > 0) l = mid;
        else r = mid;
    }
    cout << setprecision(4) << fixed <<l << endl;
   
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> p >> q >> r >> s >> t >> u)
    {   
        solve( );
    }
    return 0 ; 
}


