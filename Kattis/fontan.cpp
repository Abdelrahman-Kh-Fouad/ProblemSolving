#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , m ;cin>>n >> m ;
    vector<vector<char>> arr ; 
    arr.assign(n , vector<char>(m) );
    for(int i =0 ;i < n ;i++)
        for(int j =0 ;j < m ;j++)
            cin>>(arr)[i][j];
    bool f =1 ; 
    while(f)
    {
        f= 0 ;
        for(int i =1 ;i < n ;i++)
        {
            for(int j =0 ;j < m ;j++)
            {
                if(arr[i-1][j]=='V' )
                {
                    if(arr[i][j]=='.')f |=1 , arr[i][j]='V';
                    else if(arr[i][j]=='#' )
                    {
                        if(j+1 < m && arr[i-1][j+1]=='.') f|=1 , arr[i-1][j+1]='V';
                        if(j-1 >=0 && arr[i-1][j-1]=='.') f|=1 , arr[i-1][j-1]='V'; 
                    }
                }
            }
        }
    }        
    for(int i =0 ;i < n ;i++)
    {
        for(int j =0 ;j < m ;j++)
            cout<<arr[i][j];
        cout<<endl;
    }
    return 0 ; 
}
