#include <bits/stdc++.h>
using namespace std ;
int n;
double a0 , an_1;
int main() {
    int t ; cin>>t;
    while (t--)
    {
        cin>>n>>a0>>an_1;
        double sum=0;
        double c ;
        for (int i=0 ;i<n  ;i++)
            cin>>c,sum+=(n-i)*c;
        printf ("%0.2f\n",(n*a0 +an_1-2*sum)/(n+1));
        if(t)
            cout<<endl;
    }
    return 0;
}
