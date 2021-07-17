#include<bits/stdc++.h>
using namespace std ;
int memo [150 ][150]; 
int dp (string &a ,string &b , int i  = 0,int j =0 )
{
    if(i == a.size() || j==b.size())
        return 0 ;
    int &stat = memo[i][j];
    if(stat !=-1)
        return stat ;
    
    if(a[i] == b[j])
        return stat = dp(a , b , i +1 , j+1 ) +1 ;
    else  
        return stat = max ({dp(a , b , i+1 , j ) ,  dp(a , b , i ,j+1 ) , dp(a ,b , i+1 ,j+1 )});
}
int main ()
{
    string a , b ; 
    int t =1 ; 
    while(getline(cin ,a ) && a !="#")
    {
        getline(cin , b ); 
        memset(memo , -1 , sizeof memo);
        printf("Case #%d: you can visit at most %d cities.\n" , t++ , dp(a , b ));
    }
}