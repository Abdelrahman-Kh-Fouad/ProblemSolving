#include <bits/stdc++.h>
using namespace std ;
#define N 1000000
vector<int >prime;
vector<bool>isprime(N+1,1);
int pow (int x , int y )
{
    int res =1;
    if(y==0)
        return res;
    res *= pow(x,y/2);
    res *=res;
    if(y%2)
        res*=x;
    return res;
}
void sieve()
{
    isprime[0]=isprime[1]=0;
    prime.push_back(1);
    for (int i = 2 ; i <=N ;i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            for(int j = i*2 ; j<=N ;j+=i)
                isprime[j]=0;
        }
    }
}
bool test (int n )
{
    int length = floor(log10(n))+1 ;
    for(int i =0 ;i < length  ;i++)
    {
        int tmp= n%10;
        n/=10;
        n +=pow(10,length-1)*tmp;
        if(!isprime[n])
            return 0;
    }
    return 1 ;
}
int main() {
    int l ,r ;
    sieve();
    vector<int >rsq(N+1,0);
    for(int i =100 ; i<=N; i++)
        rsq[i]=rsq[i-1]+test(i);
    while (cin>>l, l!=-1)
    {
        cin>>r;
        int res =rsq[r]-rsq[l-1];
        if(res==1)
            cout<<"1 Circular Prime."<<endl;
        else if (res)
            cout<<res <<" "<<"Circular Primes."<<endl;
        else
            cout<<"No Circular Primes."<<endl;
    }
    return 0;
}

