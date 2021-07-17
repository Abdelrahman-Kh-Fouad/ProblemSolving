#include<bits/stdc++.h>
using namespace std ;
int main()
{
    string s ; 
    int g = 34943;
    while(getline(cin , s ) && s !="#")
    {
        unsigned long long m =0 ;
        for(auto i : s )
            m <<= 8 , m +=int(i) , m %=g ;
        m <<=16 ;
        m %=g;
        int res = (g - m)%g  ;  
        printf("%02X %02X\n" , res >> 8 ,res % (1<<8));
        
    }
}