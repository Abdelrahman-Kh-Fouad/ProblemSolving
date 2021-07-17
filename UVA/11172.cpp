#include <bits/stdc++.h>
#define ll long long
using namespace std ;
int main() {
    int t ;cin>>t;
    while (t--)
    {
        ll x ,y ;
        cin>>x>>y;
        if(x>y)
            cout<<">"<<endl;
        else if (x<y)
            cout<<"<"<<endl;
        else
            cout<<"="<<endl;

    }
    return 0;
}
