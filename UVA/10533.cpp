#include <bits/stdc++.h>
using namespace std ;
#define N 1000000
vector<bool>isprime(N+1 , 1);
vector<int >prime;
 int binary( int t ,bool lower)
{
    int ans = -1, start = 0, end = prime.size()-1;
    while(start <= end)
    {
        int mid = (start + end )/2;
        if(lower)
        {
            if(prime[mid] >= t)
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        else
        {
            if(prime[mid] <= t)
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
    }
    return ans;
}
void sieve()
{
    isprime[0]=isprime[1]=0;
    prime.push_back(1);
    for(int i =2 ; i <=N;i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            for(int j =i*2 ; j <=N ;j+=i)
                isprime[j]=0;
        }
    }
}
int sum (int n )
{
    int res =0;
    while(n)
        res+=n%10 , n/=10;
    return res;
}
int main() {
    sieve();
    vector<int>sums(prime.size()+1,0);
    for(int i =1 ;i<=prime.size();i++)
        sums[i]=sums[i-1]+isprime[sum(prime[i])];

    int n ; cin>>n;
    while (n--)
    {
        int l ,r ; cin>>l>>r;
         l = binary(l,1);
         r = binary(r,0);
        cout<<sums[r]-sums[l-1]<<endl;
    }
    return 0;
}

