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
int k=1 ; 
string s ;
vector<ull>fact; 
void solve()
{       
    cin >> s ;
    unordered_map<int,int>mp ; 
    for(auto i : s ) mp[i]++;
    ull down =1 ; 
    for(auto &i : mp )
        down *= fact[i.ss]; 
    
    printf("Data set %d: %lld\n" , k++ , (ull)fact[sz(s)] / down );

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact.assign(21 ,1 );
    for(ll i = 1;i  <=20 ;i++ )
        fact[i]= i * fact[i-1];
    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}