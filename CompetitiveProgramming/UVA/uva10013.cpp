#include <bits/stdc++.h>
using namespace std ;
int main() {
    int n;cin>>n;
    while (n--)
    {
        int limit ;cin>>limit;
        int tmp1 ,tmp2;
        vector<int>arr(limit,0);
        for (int i =0 ;i < limit ;i++)
        {
            cin>>tmp1>>tmp2;
            arr[i]=tmp2+tmp1;
        }
        arr.reserve(limit+1 );

        for(int i =limit-1 ;i>=0 ;i--)
        {
            if (i)
                arr[i-1] += arr[i]/10 ,arr[i] %=10;
        }
        for(auto i : arr)cout<<i;
        cout<<endl;
        if(n)
            cout<<endl;

    }
    return 0;
}
