#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n ; 
    int arr[n];
    for(int i =0 ;i <n ;i++)cin>>arr[i];
    
        unsigned long long  res =1;
 
    bool trig=0 ;
    ull sum=0;
    bool start=0;
    for (int i =0 ;i <n ;i++)
    {
        if (arr[i]==0 && !start)
            continue;
        else
        {
            start=1;
            if (arr[i]==0 && trig )
                sum++;
            else if (arr[i]==0 && !trig)
                trig=1,sum++;
            else if (arr[i]==1 && trig)
            {
                trig=0 ;sum++; res*=sum;
                sum=0;
            }
        }
 
    }
    cout<<(( start==0 )? 0 : res)<<endl;;
    return 0 ; 
}