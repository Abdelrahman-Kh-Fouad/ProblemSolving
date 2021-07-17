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
int tt =0 ;
void solve()
{
    int n ; cin>>n;
    bool f =0 ;
    double res = 0,tryy = 1;
    for(int i=0 ;i <n ;i++)
    {
        double x, p ; 
        cin>> x>> p ;
        if(x> 0) res +=x*p , f |=1;
        else res-=x*p , tryy-=p;
    }   
    if(f)
        printf("Case %d: %.02f\n",++tt , res /tryy );
    else 
        printf("Case %d: God! Save me\n" ,++tt); 
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