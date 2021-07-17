#include <bits/stdc++.h>
using namespace std ;
int main() {
    long long  com[1<<10];
    memset(com , 0 , sizeof(com));
    com[1]=1;com[2]=2;
    int a=1,b=1;
    for(int i =3  ; ; i++)
    {
        com[i]=com[i-1]+a+b;
        int tmp =b;
        b= a+b;
        a = tmp;
        if(com[i] > INT_MAX)
            break;
    }
    int n ;
    while (cin>>n , n!=-1)
        cout<<com[n]<<" "<<com[n+1]<<endl;

    return 0;
}
