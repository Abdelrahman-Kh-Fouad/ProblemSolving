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
bool cmp(pair<int,char> x,pair<int,char>y)
{
    if(x.ff == y.ff)
        return x.ss < y.ss ; 
    return x.ff > y.ff ;
    
}
void solve()
{
    int t  ;cin>> t ; 
    string s ;
    getline(cin ,s);
    vector<pair<int , char>>ch(26 , {0,0});
    for(int i =0 ; i<26 ;i++)
        ch[i].ss = 'A'+i; 
    while (t--)
    {
        getline(cin, s );
        for(auto &i :s  )
        {
            if(isalpha(i))
            {
                if(isupper(i))i= tolower(i);
                ch[i-'a'].ff++;
            }
        }
    }
    
    sort(all(ch) , cmp);
    for(auto &i : ch )
        if(!i.ff)break;
        else cout<< i.ss <<" "<<i.ff<<endl; 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

   
    solve();
    
    return 0 ; 
}