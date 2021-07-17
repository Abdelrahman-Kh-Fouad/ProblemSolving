#include <bits/stdc++.h>
using namespace std ;

int main ()
{
    int n ,d ,r ;
    while(cin>>n>>d>>r && !(n==0 && d==0 && r==0))
    {

        vector<int>mor (n) , after(n);
        for (int i =0 ;i < n ;i++)
            cin>>mor[i];
        for (int i =0 ;i < n ;i++)
            cin>>after[i];
        sort(after.begin() ,after.end());
        sort(mor.begin() ,mor.end(),greater<int>());
        int sum =0 ; 
        for ( int i =0 ;i < n ;i++)
            if(after[i]+mor[i] > d )
                sum+=r*(after[i]+mor[i] - d);
        cout<<sum<<endl;
    }
    return 0 ;
}