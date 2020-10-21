#include <bits/stdc++.h>
using namespace std ;
bool isprime[33];
bool used [17] ;

void prime()
{
    isprime[0]==isprime[1]==0;
    for(int i =2 ;i*i<33;i++)
    {
        if(isprime[i])
        {
            for(int j =i*2 ; j<33 ;j+=i)
                isprime[j]=0;
        }
    }
}
void go (vector<int>&arr ,int ind )
{
    if(ind==arr.size())
    {
        if(isprime[*(arr.end()-1)+1])
        {
            for(int i =0 ;i < arr.size() ;i++)
            {
                cout<<arr[i];
                if(i!=arr.size()-1)cout<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    for (int i =2 ;i <=arr.size();i++)
    {
        if(used[i])continue;
        if (isprime[arr[ind-1]+i])
        {
            arr[ind]=i;
            used[i]=1;
            go(arr,ind+1);
            used[i]=0;
        }
    }
}
int main() {
    memset(isprime , 1 , sizeof(isprime));
    prime();

    int n ;
    int t =1 ;
    while (cin>>n)
    {
        if(t!=1)
            cout<<"\n";
        memset(used , 0 , sizeof(used ));
        used[1]=1;
        vector<int>tmp(n,1);
        printf("Case %d:\n",t);
        go(tmp , 1);

        t++;
    }
    return 0;
}
