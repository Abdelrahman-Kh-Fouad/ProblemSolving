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
string s ; 
string a , b  ;
int memo[101][101];
int dp(int i =0  ,int j =0 )
{
    if(i==sz(a) && j==sz(b)) return 0 ;
    if(i>sz(a) || j>sz(b)) return 1e6;
    int &stat=memo[i][j];
    if(stat !=-1)return stat ;
    if(a[i] == b[j]) return stat = 1 + dp(i+1 , j+1 );
    int ch1 = dp(i +1 , j );
    int ch2 = dp(i , j+1 );
    return stat =min(ch1 ,ch2 )+1;        
}
void print(int i =0  ,int j =0 )
{
    if(i == sz(a) && j== sz(b)) return  ;
    if(i==sz(a)) while(j<sz(b))cout<<b[j++];
    if(j==sz(b)) while(i<sz(a))cout<<a[i++];
    if(s[i] == b[j])  cout<< a[i] , print(i+1 , j+1 );
    else
    {
        int ch1 = dp(i +1 , j );
        int ch2 = dp(i , j+1 );
        if(ch1+1 == dp(i , j )) cout<<a[i],print(i+1 , j);
        else if(ch2+1 == dp(i , j )) cout<<b[j],print(i ,j +1 );
    } 
    
}
void solve()
{
    stringstream in (s);
    in>>a >>b ;
    memset(memo , -1 , sizeof memo);
    dp();
    print();
    cout<<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(getline(cin , s ))
    {
        solve();
    }
    return 0 ; 
}