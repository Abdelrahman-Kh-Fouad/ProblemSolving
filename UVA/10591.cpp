#include <bits/stdc++.h>
#define ll long long
using namespace std ;
ll go(ll num)
{
    ll sum=0;
    while (num)
    {
        int tmp=(num%10);
        sum+=tmp*tmp;
        num/=10;
    }
    return sum;
}
int main() {
    ll t ; cin>>t;
    for (ll k =1 ; k<=t ;k++)
    {
        long long n ; cin>>n;
        ll stop = n;
        bool f =0;
        set<ll>ch;
        while(1)
        {
            if(n==1)
                break;
            if (ch.count(n))
            {
                f=1;
                break;
            }

            ch.insert(n);
            n=go(n);

        }
        if(!f )
            cout<<"Case #"<<k<<": "<<stop<<" is a Happy number."<<endl;
        else
            cout<<"Case #"<<k<<": "<<stop<<" is an Unhappy number."<<endl;


    }
    return 0;
}
