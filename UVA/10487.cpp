#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int l =1 ;;l++)
    {
        int n ;cin>>n;
        if (!n)break;
        int arr[n];for(int i =0 ;i < n ;i++)cin>>arr[i];
        vector<int>sum;
        for (int i =0 ; i < n ;i++)
            for (int j =0 ;j < n ;j++)
                if (i!=j )sum.push_back(arr[i]+arr[j]);
        int q ;cin>>q;
        int tmp ;
        cout<<"Case "<<l<<":"<<endl;

        for (int i =0 ; i< q ;i++)
        {
            cin>>tmp;
            pair<int,int>res={INT_MAX,0};
            for (auto j: sum)
                res=min(res , {abs(j-tmp) ,j });
            
            cout<<"Closest sum to "<<tmp<<" is "<<res.second<<"."<<endl;
        }
    }
    return 0;
}
