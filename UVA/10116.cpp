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

int n , m , s ;
map<char , pair<int,int>>dir ;
inline int valid (vector<vector<char>>&arr ,vector<vector<int>>&memo, int x ,int y )
{
    if (!(x >= 0 && x < sz(arr)&& y >=0 && y<sz(arr.front()))) return 0 ; 
    else if( memo[x][y] !=-1) return -1 ; 
    else  return 1 ;
}
pair<int,int> add(pair<int,int>& a , pair<int,int>&b)
{
    return {a.ff + b.ff , a.ss + b.ss};
}
void solve()
{
    vector<vector<char>>arr(n ,vector<char >(m) );
    vector<vector<int>>memo(n , vector<int>(m , -1 )) ; 
    for(int i  =0 ;i  <n ; i++)
    for(int j =0 ;j < m ;j++)
        cin>>arr[i][j];
    pair<int ,int >cur ={0, s-1} , prev ;

    int sum = 0;
    while (valid(arr , memo , cur.ff , cur.ss )==1)
    {
        memo[cur.ff][cur.ss] =sum++;     
        prev =cur ;   
        cur = add(cur , dir[arr[cur.ff][cur.ss]]);
    }
    int stat = valid(arr , memo , cur.ff , cur.ss );
    if (stat ==-1)
        printf("%d step(s) before a loop of %d step(s)\n" , memo[cur.ff][cur.ss] , memo[prev.ff][prev.ss]+1 -memo[cur.ff][cur.ss] );
    else 
        printf("%d step(s) to exit\n" , memo[prev.ff][prev.ss] +1 );

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    dir['N']={-1 ,0};
    dir['S']={1 ,0};
    dir['E']={0 ,1};
    dir['W']={0 ,-1};
    while(cin>> n>> m >>s && n!= 0 && m!=0 && s!=0  )
        solve();
    return 0 ; 
}