#include <bits/stdc++.h>
using namespace std ;
#define N (int)1e6
vector<bool >isprime(N+1,1);
vector<int>prime;
void sieve()
{
    isprime[0]=isprime[1]=0;
    prime.push_back(1);
    for(int i =2 ;i *i<= N;i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            for (int j= i*2 ;j<=N;j+=i)
                isprime[j]=0;
        }
    }
}
int main()
{
    sieve();
    int n ;
    while (cin>>n ,n!=0)
    {
        int maxx=-1;
        pair<int,int>res ;
        auto  it =lower_bound(prime.begin() , prime.end() ,n);
        for (auto i =++prime.begin() ; i!=it;i++)
        {
            if (n-(*i)>=0&& isprime[n-(*i)] && abs(n-2*(*i)>maxx ))
                maxx=abs(n-2*(*i)) , res={*i , n-(*i)};
        }
        printf("%d:\n",n);
        if(maxx==-1)
            cout<<"NO WAY!"<<endl;
        else
            printf("%d+%d\n",res.first,res.second);
    }

    return 0;
}
