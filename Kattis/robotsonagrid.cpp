#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll MOD = (1<< 31) -1;
inline bool valid (vector<vector<char>>&arr , int x ,int y ){
    return (x < sz(arr) && y < sz(arr.front()) && x>= 0 && y>= 0 && arr[x][y] == '.');
}
ll memo1 [1001][1001];
ll memo2 [1001][1001];
ll dp1(vector<vector<char>>&arr , int x =0  , int y = 0 )
{
    if(x ==sz(arr)-1  &&y == sz(arr.front())-1 )return 1 ;
    ll &stat = memo1[x][y];
    if(stat !=-1) return stat ;
    ll ch1 = valid(arr , x+1 , y )? dp1(arr ,x+1 , y ): 0;
    ll ch2 = valid(arr , x , y+1 )? dp1(arr ,x , y+1 ): 0;
    return stat = (ch1 %MOD +ch2 %MOD )%MOD;
}
int xx[]={0 , 0 , 1 , -1 };
int yy[]={1 , -1 , 0 , 0 };

ll dp2(vector<vector<char>>&arr , int x =0  , int y = 0 )
{
    if(x ==sz(arr)-1  &&y == sz(arr.front())-1 )return 1 ;
    ll &stat = memo2[x][y];
    if(stat !=-1) return stat ; 
    ll res =0 ;
    for(int i =0 ;i  <4 ;i++)
    {   
        if(valid(arr , x +xx[i] , y+yy[i]))
        {
            arr[x+xx[i]][y+yy[i]] ='6';
            res += dp2(arr , x+xx[i] ,y+yy[i])%MOD;
            arr[x+xx[i]][y+yy[i]] ='.';
        }
    }
    return stat = (res )%MOD;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ;cin>>n ; 
    vector<vector<char>>arr(n,vector<char>(n));
    for(int i =0 ; i <n ;i++)
        for(int j =0 ;j < n ;j++)
            cin>>arr[i][j];
    memset(memo1 , -1 ,sizeof memo1);
    memset(memo2 , -1 ,sizeof memo2);

    ll res1 = dp1(arr);
    ll res2 = dp2(arr);
    if(res1)cout<<res1 <<endl;
    else if(res2) cout<<"THE GAME IS A LIE"<<endl;
    else cout<< "INCONCEIVABLE"<<endl;
    return 0 ; 
}