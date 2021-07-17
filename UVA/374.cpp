#include<bits/stdc++.h>
using namespace std ;
int B,P,M;
long long  solve (int b ,int p)
{
    if(p == 0 )return 1 ;
    if(p%2)
        return ((solve(b , p-1)%M)*b)%M;
    else
    {
        long long  tmp = solve(b, p/2)%M;
        return (tmp *tmp)%M;
    }
    
}

int main ()
{
    //B^p mod m
    while(cin>>B>>P>>M)
    {
        cout<<solve(B,P)%M<<endl;
    }


}