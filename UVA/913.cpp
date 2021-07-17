#include <bits//stdc++.h>
#define ll long long
inline ll ii(ll n )
{
    return 2*n-1;
}
using namespace std;
int main() {
   ll n ;
   while(cin>>n)
   {
        ll level=(n+1)/2;
        ll i = level*(level+1)-level;
        cout<<ii(i)+ii(i-1)+ii(i-2)<<endl;
   }
    return 0;
}
//2*(n-2)+10
 //