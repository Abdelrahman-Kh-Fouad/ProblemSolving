#include<bits/stdc++.h>
using namespace std ;
string s ; 

int memo [1000][1000]; 
int dp(int i =0 ,int j =s.length()-1 )
{
    
    if(j- i < 1 )
        return 0 ;
    
    int &stat = memo[i][j];
    if( stat !=-1) return stat ; 

    if(s[i]==s[j]) return stat = dp(i+1 , j-1 );
    else 
        return stat = min( { dp(i , j-1 ) , dp(i+1 , j) , dp(i+1 , j-1 ) }  )+1;
}
int main ()
{
    int k =1 ;
    int t ; cin>>t ;
    while(t--)
    {
        cin>>s;
        memset(memo ,-1 , sizeof memo);
        printf("Case %d: %d\n" , k++ , dp());   
    }
}