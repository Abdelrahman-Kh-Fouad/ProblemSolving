#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<ll>primes ; 
vector<bool>is_prime(1<<16+1 , 1 );
void sieve()
{
    primes.push_back(2);
    for(ll i =3 ; i<=1<<16 ; i+=2)
    {
        if(is_prime[i])
        {
            for(ll j = 2 * i ; j* j <=1<<16 ;j+=i )
                is_prime[j]=0;
            primes.push_back(i);
        }   
    }
}
int main ()
{
    sieve();
    ll n ; 
    while (cin>>n && n )
    {
        bool neg = n < 0 ; 
        n = abs(n);
        set<ll >res ; 

        for(ll i = 1 ; i* i <=n ;i++)
            if(n % i ==0 && i !=1 )res.insert(i);
        bool k = 0 ;         
       

        for(auto i = res.begin() ; i!=res.end()&& !k ; i++)
        {
            ll num  =1 ;
            ll cnt =0 ;  
            while(num <n)
                num *=*i ,cnt++; 
            
            if(num == n)
            {
                if(!neg|| (neg && cnt %2))
                {
                    cout<<cnt<<endl;
                    k =1 ;
                }
            }
        }
        if(!k)
            cout<<1 <<endl;

    }
    return 0 ; 

} 