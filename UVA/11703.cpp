#include <bits/stdc++.h>
using namespace std ;
#define ll unsigned long long 
ll  memo[(int)1e7+1];
ll  dp(int num )
{
    if(num<=0)
        return 1; 
    ll  &stat = memo[num];
    if(stat !=-1 )return stat ;
    
    return stat = (dp(floor(num-sqrt(num))) + dp(floor(log(num))) +dp(floor(num * sin(num)*sin(num))))%1000000;
}
int main()
{
    memset(memo , -1 , sizeof(memo));
    int  n ; 
    while(cin>>n && n!=-1)
        cout<<dp(n)<<endl;
}