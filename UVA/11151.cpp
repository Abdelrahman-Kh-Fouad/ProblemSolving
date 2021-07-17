#include<bits/stdc++.h>
using namespace std ;
string s ; 
int memo [1000][1000];
int dp (int i =0  , int j=s.length()-1)
{
    if(j-i <1)
        return (j-i ==0 ) ? 1 : 0 ;
    int &stat = memo[i][j];
    if(stat !=-1)return stat ;
    if(s[i] == s[j])
        return stat= dp(i+1 , j-1)+2 ;
    return stat = max({ dp(i+1 , j )   ,dp(i+1 , j-1) ,dp(i, j-1)});
}
int main ()
{
    //freopen("in" , "r", stdin);
    int t ; cin>>t; 
    getline(cin , s );

    while(t--)
    {
        getline(cin , s );
        memset(memo ,-1 , sizeof memo);
        cout<<dp()<<endl;
    }
}