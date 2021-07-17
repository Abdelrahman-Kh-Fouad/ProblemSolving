#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t ;cin>>t;
    while (t--)
    {
        int n ; cin>>n;
        int minn= INT_MAX;
        float x = sqrt(n);
        for (int i =1 ;i <= floor(x) ;i++)
            for (int j =1 ; j<=ceil(x);j++)
                for (int k =1 ; k<=ceil((float)n/(i*j)) ;k++)
                    if (k*i*j == n )
                        minn=min(minn,2*(i*j)+2*(k*i)+2*(k*j));
        cout<<minn<<endl;
    }
    return 0;
}
