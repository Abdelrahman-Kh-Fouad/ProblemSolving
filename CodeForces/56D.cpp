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


string s , t ;
int memo[1002][1002];
int dp(int i =0 , int j =0 ) 
{
    if(i==s.length() && j ==t.length())return 0 ;
    if(i==s.length()) return dp(i , t.size()) + t.size()- j  ;
    if(j == t.length()) return dp(s.size() , j ) + s.size() - i ;

    int &stat = memo[i][j];
    if(stat !=-1)return stat ;
    stat = INT_MAX;
    if(s[i] ==t[j]) return stat = dp(i +1 ,j +1 );
    return stat =min( { dp(i+1 , j )+1   , dp(i , j+1 )+1  ,dp(i+1 , j+1) +1 }) ;

}
int cnti , cntj ; 
void trace (int i ,int j )
{
    if(i==s.length() && j ==t.length())return;
    else if(i==s.length()) printf("INSERT %d %c\n" , cnti++ + 1  , t[cntj++]) , trace (i ,j+1) ;
    else if(j == t.length()) printf("DELETE %d\n" , cnti+1),cntj++,  trace(i+1 , j);
    if(i<s.length() && j < t.size())
    {
        if(s[i] == t[j])cnti++ ,cntj++ , trace(i+1 , j+1 );
        else 
        {
            int dpval = memo[i][j];

            if(dp(i+1 , j)+1 == dpval  )
                printf("DELETE %d\n" ,cnti+1 ) , trace(i+1 , j );
            else if(dp(i+1 , j+1 ) +1 == dpval )
                printf("REPLACE %d %c\n" ,cnti++ +1  , t[cntj++] ),trace(i+1 ,j +1);
            else if(dp(i ,j+1)+1   ==dpval  )
                printf("INSERT %d %c\n" , cnti++ +1 , t[cntj++]) ,trace (i ,j+1 );
        }
    }
}
void solve()
{
    getline(cin , s );
    getline(cin , t );
    memset(memo , -1 ,sizeof memo);
    cout<<dp()<<endl;
    trace(0 ,0);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0 ; 
}