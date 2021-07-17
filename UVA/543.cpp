#include <bits/stdc++.h>
using namespace std;
#define N (int)1e6
vector<bool>prime( N, 1);
void sieve()
{
    prime[1]=prime[0]=0;
    for (int i =2 ;i*i<=N ;i+=1)
    {
        if(prime[i])
        {
            for(int j =i*2 ; j<=N ;j+=i)
                prime[j]=0;
        }
    }
}
int main() {
    sieve();
    int n ;

    while (cin>>n , n!=0)
    {
        int maxx=-1;
        pair<int,int>res={-1,-1};
        for (int i =1 ;i <= ceil(n/2);i++)
        {
            if(prime[i]&& prime[n-i])
                if(maxx<abs(i-n+i))
                    maxx=abs(i-n+i) , res={i, n-i};
        }
        if (res==make_pair(-1,-1))
            cout<<"Goldbach's conjecture is wrong."<<endl;
        else
            cout<<n<<" = "<<res.first<<" + "<<res.second<<endl;
    }
    return 0;
}
