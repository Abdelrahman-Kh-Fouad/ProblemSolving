#include <bits/stdc++.h>
using namespace std ;

int go(int  n )
{
    if(n <=100 )
        return go(go(n+11));
    if(n>=101)
        return n-10;
}
int main() {
    int n;
    while(cin>>n,n!=0)
        printf("f91(%d) = %d\n",n,go(n) );

    return 0;
}
