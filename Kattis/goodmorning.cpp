#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
set<int >num ;
vector<int>vnum;
void go(vector<vector<int>>&arr ,  int n , int m , int number = 0)
{   
     num.insert(number);
    if(n >=0 && n <sz(arr) && m>= 0 && m<sz(arr.front()) && arr[n][m]!=-1 && floor(log10(number)) +1 < 3 )
    {
        
        if( (n !=3 || m != 1)||((n ==3 && m == 1) && number !=0) )
            go(arr , n , m , number *10 + arr[n][m]);    
        
        go(arr , n+1 ,m ,number*10 + arr[n][m] );
        go(arr , n ,m+1 ,number*10 + arr[n][m] );
        go(arr , n+1 ,m ,number );
        go(arr , n ,m+1 ,number );
    }

}
void init()
{
    vector<vector<int>>arr ={{1,2,3},
                  {4,5,6},
                  {7,8,9},
                  {-1,0,-1}};
    go(arr , 0, 0);
    for(auto &i : num)
        vnum.pb(i);
}
void solve()
{   
    int k ;cin>> k ;
    
    for(int i =0 ;i < sz(vnum) ;i++)
    {
        if(vnum[i]>=k )
        {
            int r = abs(vnum[i] - k) ;
            int l = abs(k - ((i-1>=0)?vnum[i-1] : 0));
            if(r <l )
                cout<<vnum[i]<<endl;
            else 
                cout<<vnum[i-1]<<endl;
            break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    //for(auto &i : vnum)cout<<i<<endl;
    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}