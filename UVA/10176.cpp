#include <bits/stdc++.h>
using namespace std ;
#define getbit(n , bit ) (bool)((n) & 1<<(bit))
int main ()
{
    int m = 131071-1;
    int size = floor(log2(m))+1;
    string s ;
    string tmp;  
    while(cin>>tmp)
    {          
        s+=tmp;
        if(s.back()!='#')
            continue;
        else
            s.pop_back();
        reverse(s.begin() , s.end());
        int num = 0 ;
        for(int i =0 ;i < s.length() ;i++ )
        {
            num +=(s[i]-'0');
            num *=2;
            num %=131071;
        }
        cout<<((num)? "NO" : "YES")<<endl;
        s="";
    }

}