#include <bits/stdc++.h>
using namespace std;
//ifstream in ("../ex.txt");
set <int>primes;
int n;
bool ch[17];

void go (vector<int>&v,int ind =1)
{

    if (ind==n)
    {
        for (int i =0 ;i < n ;i++  )cout<<v[i]<<((i==n-1)?"" : " ");
        cout<<endl;
        return;
    }
    for (int i=1 ; i <=n ;i++)
        if (!ch[i] )
        {
            if (!primes.count(i+v[ind-1]))continue;
            if (ind ==n-1 &&!primes.count(i+v[0]))continue;
            ch[i]++;
            v[ind]=i;
            go(v,ind+1);
            ch[i]=0;
        }
}

int main()
{

    for (int i =1 ; i <= 32;i++ )
    {
        bool f =1;
        for (int j =2 ; j*j <=i ;j++)
        {
            if (i % j ==0){
                f=0;
                break;
            }
        }
        if (f ) primes.insert(i);
    }
    ch[1]=1;
    int cnt=1;
    while (cin>>n)
    {
        vector<int>tmp(n,1);
        if (cnt !=1 )cout<<endl;
        cout<<"Case "<<cnt++<<":\n";
        go(tmp);
        
    }

    return 0;
}
