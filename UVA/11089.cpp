#include <bits/stdc++.h>
#define ll  long long
using namespace std ;

int main() {

    vector<unsigned ll>fib = {1,2};
    for(int i =2 ;;i++)
    {
        fib.push_back(fib[i-1]+fib[i-2]);
        if (fib[i] > LONG_LONG_MAX)
            break;
    }
    reverse(fib.begin() , fib.end());
    ll t ; cin>>t;
    while (t--)
    {
        ll n ;cin>>n;
        bool f =0;
        for(auto i : fib )
        {
            if(n>=i)
                f=1;
            if(f)
            {
                if(n>=i)
                    cout<<1, n-=i;
                else
                    cout<<0;
            }

        }
        cout<<endl;

    }
    return 0;
}
