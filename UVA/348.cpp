#include<bits/stdc++.h>
using namespace std ; 
 
long long  memo [50 ][50];
int toprint[50][50];
int n ; 
long long dp (vector<pair<int,int>>&arr ,int i =0  ,  int j = n-1  )
{
    if(i == j )
        return 0;
    long long  &stat  = memo[i][j];
    if(stat !=-1)
        return stat ; 
    stat = LONG_LONG_MAX;
    for(int k =  i ; k <=j ;k++)
    {
        int calc = (dp(arr , i ,k ) +dp(arr , k+1 , j ))+(long long )arr[i].first * arr[k].second * arr[j].second; 
        if(stat >calc )
        {
            stat = calc ; 
            toprint[i][j] = k ;
        }
    }
    return stat;
    
}
void print(int i =0 , int j = n-1 )
{
    if(j> j )
        return ;
    if(i== j )
    {
        printf("A%d" , i+1);
        return  ;
    }
    cout<<"(";
    print(i , toprint[i][j]);
    cout<<" x ";
    print(toprint[i][j] +1 , j );
    cout<<")";
}
int main ()
{ 
    int t = 1 ;
    while(cin>>n && n !=0)
    {
        memset( memo , -1 , sizeof memo );
        memset(toprint , 0 , sizeof toprint);
        vector<pair<int,int>>arr (n);
        for(int i =0 ;i < n ; i++)
            cin>>arr[i].first >>arr[i].second;
        dp(arr );

    // for(int i =0 ;i < n ; i ++ )
    // {
    //     for(int j =0 ;j < n ; j++)
    //         cout<<toprint[i][j]<<" ";
    //     cout<<endl;
    // }
        printf("Case %d: " ,t++ );
        print();
        cout<<endl;
    } 

}