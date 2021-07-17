#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[3];
    for(int i =0 ;i <3 ;i++)
        cin>>arr[i];
    int cnt =0;
    int minuts=29;
    while(!(arr[0]<=0 && arr[1] <=0 && arr[2] <=0))
    {
        arr[cnt%3] -=2;
        minuts++;
        cnt++;
    }
    cout<<minuts<<endl;
    return 0;
}
