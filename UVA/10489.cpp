#include<bits/stdc++.h>
using namespace std ;
int main ()
{
    int t ; cin>>t ; 
    while(t--)
    {
        int n , b ; cin>>n>>b;
        int res =0;
        for(int it =0 ;it< b ;it++)
        {
            int k ; cin>>k ;
            int tmp; 
            int sum =1  ;
            for(int boxes =0 ; boxes <k ;boxes++ )
                cin>>tmp ,sum *=tmp , sum = sum % n  ;
            res +=sum;
        }   
             
        cout<< res % n  <<endl;
    }
}