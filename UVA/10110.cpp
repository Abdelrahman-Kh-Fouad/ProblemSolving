#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long temp;
    while (1)
    {
        cin>>temp;
        if (temp==0)
            return 0 ;

        cout<<(((long long )sqrt(temp)==sqrt(temp))?"yes":"no")<<endl;
    }

    return 0;
}
