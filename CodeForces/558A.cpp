#include <bits/stdc++.h>
#define f first
#define s second
using namespace std ;

int main() {
    int n ;cin>>n;
    pair<int ,int >arr [n];
    int minn = INT_MAX;
    int sum =0 , po= 0,ne=0 ;
    for (int i =0 ;i < n ;i++)
    {
        cin>>arr[i].f >> arr[i].s;
        sum+=arr[i].s;
        if(arr[i].f > 0 ) po++;
        if (arr[i].f < 0 ) ne++;
    }
    sort(arr ,arr+n);
    if (po != ne )
    {
        if (ne > po)
            for (int i =0 ;i < n- 2*po-1 ;i++)
                sum-=arr[i].s;
        else
            for (int i =n-1 ;i >=2*ne+1  ;i--)
                sum-=arr[i].s;
    }
    cout<<sum<<endl;
    return 0;
}
