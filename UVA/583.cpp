#include<bits/stdc++.h>
using namespace std ;
vector<long long >primes ; 
vector<int>is_prime; 
void sieve ()
{
    is_prime.assign(46349 , 1 );is_prime[0]=is_prime[1] = 0 ;
    
    for(long long i =2;i<=46345 ; i++)
    {
        if(is_prime[i])
        {
            for(long long  j = i *2 ; j * j <=46345 ; j+= i )
                is_prime[j]=0;
            primes.push_back(i);
        }
    }
}
int main()
{   
    sieve();
    long long  n ;  
    while(cin>>n , n)
    {
        printf("%d = " , n );
        vector<int >res ; 
        if(n < 0 ) cout<<"-1 x ";
        n = abs (n );

        for(long long  i = 0  ; i < primes .size() && primes[i]*primes[i] <=n   ;i++)
        {
            while(n % primes[i] ==0 )
            {
                res.push_back(primes[i]);
                n /= primes[i];
                //cout<< n <<endl;
            }    
        }
        if(n != 1)res.push_back(n);
        for (int i =0 ;i  <res.size() ;i++)
        {
            if(i != 0 )cout<<" ";
            cout<<res[i];
            if(i != res.size()- 1 )cout<<" x";
        }
        
        cout<<endl;

    }


    
}