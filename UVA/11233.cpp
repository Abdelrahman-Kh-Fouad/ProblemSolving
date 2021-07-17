#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
void solve()
{
    int l , n ;cin>>l >>n ; 
    unordered_map<string ,string>mp;
    unordered_set<string>ch;
    unordered_set<char>cons;

    string t1 ,t2  ;
    for(int i =0 ;i < l ; i++)
        cin>>t1>>t2 , mp[t1]=t2;
    ch.insert("o");
    ch.insert("s");
    ch.insert("ch");
    ch.insert("sh");
    ch.insert("x");
    cons.insert('a');
    cons.insert('e');
    cons.insert('i');
    cons.insert('o');
    cons.insert('u');

    for(int k =0 ; k< n ; k++)
    {
        string s ; cin>>s ;
        if(mp.count(s))
            s=mp[s];
        else if(s.back()=='y' && !cons.count(s.at(sz(s)-2)))
        {
            s.pop_back();
            s+="ies";
        }
        else if(ch.count(s.substr(sz(s)-2)) || ch.count(s.substr(sz(s)-1)))
            s+="es";
        else 
            s+="s";
        cout<<s<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
    return 0 ; 
}