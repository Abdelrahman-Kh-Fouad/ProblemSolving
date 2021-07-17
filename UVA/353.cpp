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
bool palend(string s)
{
    string rs = s;
    reverse(all(rs));
    return rs == s ; 
}
void solve()
{
    unordered_set<string>ch;
    int sum =0; 
    int n = sz(s);
    for(int i = 0;i <n ;i++)
    {
        for(int j = i ; j< n ;j++)
        {
            string sub =s.substr(i , j-i +1 );
            if(palend(sub) && !ch.count(sub))
                sum++ ,ch.insert(sub);
        }
    }
    cout<<"The string '"<< s<<"' contains "<<sum<<" palindromes."<<endl;;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(getline(cin ,s ))
    {
        solve();
    }
    return 0 ; 
}