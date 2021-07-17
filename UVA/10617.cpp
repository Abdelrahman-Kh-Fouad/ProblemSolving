#include<bits/stdc++.h>
using namespace std ;
string s ;
long long  memo[70][70];  
long long  dp(int i = 0 , int j= s.length() -1)
{
    if( i > j )return 0 ;
    if(i == j)return 1 ; 
    if ( i +1 == j )return 2 + (s[i] == s[j]);
    long long  &stat = memo[i][j];
    if(stat !=-1)return stat ; 
    stat = 0 ; 
    if(s[i] == s[j])  stat +=  1 + dp(i +1 , j-1 ); 
    return stat +=dp( i+1 , j ) + dp( i , j-1 )- dp (i +1 , j-1 );

}

int main ()
{
    int t ; 
    cin>>t ;
    getline(cin,s ); 
    while(t--)
    {
        getline(cin ,  s );
        memset( memo , -1 , sizeof memo);
        cout<<dp()<<endl;   
    }
}   