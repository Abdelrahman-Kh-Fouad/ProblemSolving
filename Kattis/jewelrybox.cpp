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

double calc(double x ,double y ,double h )
{
    return (x - 2*h )*(y -2*h) *h ;  
}
void solve()
{
    double x ,y ; 
    cin>>x >>y ; 
    // a = x - 2h 
    // b = y - 2h
    // a * b *h 
    double l =0 , r =min(x ,y )/2 ; 
    double m1 , m2  ,f1 ,f2 ;
    while(1e-9 < r-l )
    {
        m1 = l+(r-l)/3;
        m2 = r-(r-l)/3;
        f1 = calc(x ,y , m1) , f2 =calc(x , y , m2);
        if(f1 >f2 )r = m2 ;
        else l = m1 ;
    }
    printf("%0.10f\n" , calc(x , y , l));

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