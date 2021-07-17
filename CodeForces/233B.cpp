#include <bits/stdc++.h>
#define ll  long long
using namespace std;
ll go (ll n )
{
    ll sum =0 ;
    while (n!=0)
    {
        sum+=n%10;
        n /=10;
    }
    return sum;
}
int main() {
    ll n;cin>>n;
    bool f =1;
    double x ;
    for(long long  i =0; i <= 90&& f ;i++)
    {
        x= (-i + sqrt(i*i+4*n))/2.0;
        if(x ==(ll)x && go(x)==i)
            f=0;
    }
    if(f)
        cout<<-1<<endl;
    else
        cout<<(ll)x<<endl;
    return 0;
}
