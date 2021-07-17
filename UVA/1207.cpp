#include<bits/stdc++.h>
using namespace std ;
string a , b ;
vector<vector<int>> memo;
int dp(int i =0  , int j = 0 )
{
    if(i==a.length() && j==b.length())
        return 0;
    int &stat= memo[i][j];
    if(stat !=-1)
        return stat ;
    if(i==a.length())
        return stat = dp(i ,j+1 )+1;
    if(j==b.length())
        return stat = dp(i+1 ,j)+1;
    if(a[i] == b[j])
        return stat = dp(i+1 , j+1 );
    return stat =min({dp(i+1 ,j) , dp(i, j+1 ) , dp(i+1 ,j+1 )})+1 ;
}
int main()
{
    int n ,m ;
    while(cin>>n)
    {
        a="" ;b="";
        char tmp ; 
        for(int i =0 ;i < n ;i ++ )
            cin>>tmp , a.push_back(tmp);
        cin>>m;
        for(int i =0 ;i < m ;i ++ )
            cin>>tmp , b.push_back(tmp);
        memo.clear();
        memo.assign(n+1 , vector<int>(m+1 , -1));
        cout<<dp()<<endl;
    }    
}