#include <bits/stdc++.h>
using namespace std ;
int main() {
    long long n ;
    while (cin>>n, n>=0)
    {
        string s ="";
        if (!n)
            s="0";
        while(n)
        {
            s.push_back('0'+n%3);
            n/=3;
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}
