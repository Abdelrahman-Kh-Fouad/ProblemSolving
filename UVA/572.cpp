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
int n , m;
int xx[]={0 ,0 ,1 ,-1 ,1 , -1 ,-1 ,1  };
int yy[]={1 ,-1 ,0 ,0, 1 , -1 , 1 ,-1 };
inline bool valid (vector<vector<char>>&arr , int x ,int y )
{
    return (x >= 0 && x < sz(arr)&& y >=0 && y<sz(arr.front()) && arr[x][y] =='@');
}
bool go(vector<vector<char>> &arr , int x ,int y )
{
    int  res =0 ; 
    if(valid(arr , x , y ))
        res+=1 ,  arr[x][y] ='#';
    for(int i =0 ;i < 8 ;i++)
        if(valid(arr ,x+xx[i] , y+yy[i]))res+=(int)go(arr , x+xx[i] , y+yy[i]);
    return res ; 
}  
void solve()
{
    vector<vector<char>>arr(n , vector<char>(m));
    for(int i =0 ;i < n ; i++ )
        for(int j =0 ; j < m ;j++)
            cin>>arr[i][j];
    int cnt =0 ;
    for(int i =0 ;i < n ;  i++)
    for(int j = 0 ;j < m  ; j++)
    {
        if(valid(arr , i , j ))
            cnt +=(bool)go(arr , i , j );
    }
    cout<<cnt<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>n >>m && n !=0 && m!=0 )
    {
        solve();
    }
    return 0 ; 
}