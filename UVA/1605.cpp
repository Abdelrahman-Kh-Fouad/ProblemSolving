#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int n ; 
    while(cin>>n)
    {
        cout<< "2 "<<n <<" "<<n<<endl;
        for (int i =0 ;i < n ;i++)
        {   
            for (int j =0 ;j < n ;j++)
                cout<<(char)((i >= 26)? 'a'+(i-26) : i+'A');
            cout<<endl;
        }
        cout<<endl;
        for (int i =0 ;i < n ;i++)
        {
            for (int j =0 ;j < n ;j++)
                cout<<(char)((j >= 26)? 'a'+(j-26) : j+'A');
            cout<<endl;
        }
    }
    
    return 0 ;
}