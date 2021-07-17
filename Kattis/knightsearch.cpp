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
int xx []={2 , 2 , -2 ,-2 , 1 , 1 ,-1 ,-1};
int yy []={1 , -1 , -1 ,1 , -2 , 2 ,2 ,-2};
string targ = "ICPCASIASG";
int memo[30][101][101];
bool go(vector<vector<char>>&arr ,int x ,int y , int ind )
{
    if(ind== sz(targ))
        return 1 ;
    int &stat =memo[ind][x][y];
    if(stat !=-1) return stat ;
    bool res = 0; 
    for(int i  =0 ; i <8 ;i++)
    {
        int nx =x+xx[i] , ny = y + yy[i];
        if(nx >=0 &&  nx< sz(arr) && ny >=0 && ny<sz(arr.front()) && arr[nx][ny] == targ[ind])
            res |= go(arr , nx , ny , ind+1 );
    }
    return stat = res ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    vector<vector<char>>arr (n ,vector<char>(n));
    vector<pair<int,int>>start ;
    for(int i =0 ;i < n ;i++)
        for(int j =0 ; j<n ;j++)
        {
            cin>>arr[i][j] ;
            if(arr[i][j] == 'I')
                start.push_back({i , j });
        }
    bool res =0 ;
    memset(memo , -1 , sizeof(memo));
    for(auto &i : start)
        res |= go(arr , i.ff , i.ss ,1);
    cout<<(res ? "YES" : "NO")<<endl;

    return 0 ; 
}