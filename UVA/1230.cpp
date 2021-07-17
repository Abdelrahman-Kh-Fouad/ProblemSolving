#include<bits/stdc++.h>
using namespace std ;
int x , y , n ;
int z (int x , int y )
{
    if(y==0)return 1 ;
    if(y%2==1)return z(x , y-1)*x % n ;
    else
    {
        int tmp = z(x , y/2);
        return (tmp *tmp)%n ;
    }
    
}
int main ()
{
    int t ; cin>>t ; 
    while(t--)
    {
        //z = x^y mod n
        cin>>x>>y>>n;
        cout<<z(x ,y )<<endl;
 
    }
    cin>>t ; 
}