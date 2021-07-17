#include <bits/stdc++.h>
using namespace std ;

int main() {
    int  t ;cin>>t;
    while(t--)
    {
        int n ; cin>>n;
        vector<int>arr(n);
        for (int i =0 ;i <n ;i++)
            cin>>arr[i];
        bool f = 0;
        for (int i =1 ;i < n-1 && !f;i++)
        {
            if (arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                cout<<"YES"<<endl;
                cout<<i<<" "<<i+1<<" "<<i+2<<endl;
                f =1;
            }
        }
        if (!f)
            cout<<"NO"<<endl;

    }
    return 0;
}
