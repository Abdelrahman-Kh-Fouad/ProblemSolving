#include <bits/stdc++.h>
#define ll long long
using namespace std ;
int main() {
    string n ;
    while (cin>>n && n!="0")
    {
        ll sum=0;
        for(int i =0 ; i <n.size()  ;i++)
            sum+=((1<<(n.size()-i)) -1 )*(n[i]-'0');
        cout<<sum<<endl;
    }

    return 0;
}
