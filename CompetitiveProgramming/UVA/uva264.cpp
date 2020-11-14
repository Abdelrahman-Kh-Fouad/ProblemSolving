#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while(cin>>n)
    {
        int lvl = ceil((-1+sqrt(1+8*n))/2);
        lvl--;
        int post =n-(lvl*(lvl+1))/2  ;
        lvl++;
        int a =lvl-post+1 , b=post;
        if(lvl%2==0)
            swap(a,b);
        cout<<"TERM "<<n<<" IS "<<a<<"/"<<b<<endl;
    }
    return 0;
}
