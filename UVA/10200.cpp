#include <bits/stdc++.h>
using namespace std ;
#define ll long long
float roundd(float x )
{
    x*=100;
    x=(float)round(x);
    x/=100;
    return x;
}
bool isprime(ll n)
{
    if(n<=2 )
        return 1;
    if(n%2==0 )
        return 0;
    for(int i =3  ;i *i<=n ;i+=2)
        if(n%i==0)
            return 0;
    return 1;
}
int main() {
    vector<ll>sums(10000+2,0);
    for(int i =0 ;i<=10000;i++)
    {
        ll tmp = i*i+i+41;
        sums[i+1]=sums[i]+isprime(tmp);
    }
    int l,r;
    while(cin>>l>>r)
        cout<<fixed<<setprecision(2)<<roundd(100*((float)(sums[r+1]-sums[l])/(r-l+1)))<<endl;
    return 0;
}

