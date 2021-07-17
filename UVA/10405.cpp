#include<bits/stdc++.h>
using namespace std ;
string a , b ; 
int memo[1001][1001];
int dp(int i =0 , int j =0 )
{
    if(i==a.length() || j ==b.length())
        return  0 ;
    int &stat=memo[i][j];
    if(stat !=-1)
        return stat ; 
    if(a[i]==b[j])
        return dp(i+1 ,j+1)+1 ; 
    
    return  stat = max ( dp(i+1 , j ) , dp(i ,j+1 ) );
}
int main ()
{
    while (getline(cin, a ))
    {
        getline(cin, b );
        memset(memo, -1 , sizeof memo);    
        cout<<dp()<<endl;
    }
    
}
