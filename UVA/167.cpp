#include <bits/stdc++.h>
#define vv vector<vector<int>>
#define p pair<int,int>
#define f first
#define s second
using namespace std ;
//ifstream in ("../sm.txt");
set<p>ch;
int sum= 0 ,res = INT_MIN;
void go(vv & arr , int ind =0 )
{
    if (ind == 8 )
    {
        res = max (res , sum);
        return;
    }
    for (int i =0; i< 8 ;i++ )
    {
        bool f =1;
        for (auto j :ch)
        {
            if (j.f == i || abs(j.f-i) == abs(j.s-ind))
            {f=0;break;}
        }
        if (f)
        {
            ch.insert({i,ind});
            sum+=arr[i][ind];
            go(arr, ind +1);
            ch.erase({i,ind});
            sum-=arr[i][ind];
        }
    }
}
int main() {
    int k ; cin>>k;
    while (k--)
    {
        vv arr(8,vector<int>(8));
        for(int i =0 ;i < 8 ;i++)for (int j =0 ;j < 8 ;j++)cin>>arr[i][j];
        go(arr);
        cout<<setw(5)<<res<<endl;
        res=INT_MIN;sum=0;
    }

    return 0;
}
