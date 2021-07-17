#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int t ; cin>>t;
    map<char , int >mp ={{'(',1 },{')' ,-1 } ,
                        {'[' ,2 }, {']' ,-2 } };
    getchar();

    while(t--)
    {
        string s ; getline(cin ,s );
        stack<char>tt; 
        bool f =1 ; 
        for (auto i :s )
        {
            if (mp[i]>0) tt.push(i);
            else 
            {
                if ( tt.empty() )
                {
                    f = 0; 
                    break;
                }
                else 
                {
                    if (mp[tt.top()]+mp[i]==0)
                        tt.pop();
                    else{
                        f= 0; 
                        break;
                    }
                } 
            }
        }
        if ( f && tt.empty() )
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
    return 0; 
}