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
    long long n,k;

void solve()
{
    int f=0;
    while(n)
    {
        k=min(n,k);
        long long  ri=1,l=k,m;
        while(ri<l)
        {
            m=(ri+l)/2;
            if(k*(k + 1)/2 -(m-1)*m/2 > n)
                ri=m+1;
            else l=m;
        }
        f+=k-ri+1;
        n-=k*(k+1)/2-(ri-1)*ri/2;
    }
    cout<<f<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    --n; --k;
    if(k*(k+1)/2<n) cout<<"-1"<<endl;
    else solve();
}