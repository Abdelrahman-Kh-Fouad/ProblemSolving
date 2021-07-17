#include <bits/stdc++.h>
using namespace std; 
int main ()
{
    long long   n ;
    while(cin>> n , n!=0)
    {
        long long  tmp ;
        long long  sum =0;
        long long  cur =0; 
        for (int i =0 ;i < n ;i++)
        {
            cin>>tmp;
            cur+=tmp;
            if(i!=n-1)
                sum+=abs(cur);
        }
        cout<<sum<<endl;
    }
}