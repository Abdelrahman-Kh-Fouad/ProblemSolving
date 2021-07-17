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


bool isprime[(int)1e6 +1 ];
void sieve ()
{
    memset(isprime , 1 , sizeof isprime);
    isprime[0]= 0 ;
    for(int i =2 ; i <=(1e6) ;i++)
    {
        if(isprime[i])
            for(int j = i*2 ; j<=(1e6); j+=i)
                isprime[j]=0 ;
    }

}
string s ; 

void solve()
{
    int sum =0 ; 
    for(auto &i : s )
    {
        if(i >='a' && i<='z')
            sum+= i-'a'+1;
        if(i>='A' && i<='Z')
            sum+=i-'A' + 27 ;
    }
    if(isprime[sum])
        cout<<"It is a prime word.\n";
    else 
        cout<<"It is not a prime word.\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    while(getline(cin ,s ))
    {
        solve();
    }
    return 0 ; 
}