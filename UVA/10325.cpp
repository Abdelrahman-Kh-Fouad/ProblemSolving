#include<bits/stdc++.h>
using namespace std ; 
#define getbit(n , bit) (1<<(bit))&(n) 
long long  gcd (long long  a ,long long   b )
{
    if(b ==0  )return a ; 
    return gcd(b , a%b);
}
long long  lcm(long long  a , long long  b )
{
    return a *b / gcd(a , b )  ;
}
int main ()
{
    long long  n , m ; 
    while(cin>>n>>m)
    {
        long long  arr[m];
        long long  res =0; 
        for(int i =0 ;i < m;i++)cin>>arr[i];
        for(int i = 1 ;i <  1<< m ;i++)
        {
            long long  ll = 1 ;
            long long  count =0;  
            for(int bit =0 ; bit < m ;bit++)
            {
                if(getbit(i , bit))
                    ll =lcm(ll , arr[bit]),count++;
            }
            
            if( count % 2==0 )
                res -= n/ll; 
            else  
                res += n/ll;
            
            
        }
        cout<<n - res<<endl;
    }
    return 0;  
}