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
void solve()
{
    vector<pair<int,int>> f(n) ,s(n) ;
    for(int i =0 ;i  <n ;i++)   
        cin>> f[i].ff , f[i].ss = i ;     
    
    for(int i =0 ;i  <n ;i++)   
        cin>> s[i].ff , s[i].ss = i ;
    vector<pair<int, int > > tmp = f ;
    sort(all(f));
    sort(all(s));

    unordered_map<int ,int >ppp ;
    for(int i =0 ; i < n ;i++)
        ppp[f[i].ff ]=s[i].ff;
    for(int i =0 ;i  <n ;i++)
        cout<< ppp[tmp[i].ff]   <<endl;
    


    cout<<endl;
    

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    while(cin>>n ,n != 0 )
    {
        solve();
    }
    return 0 ; 
}