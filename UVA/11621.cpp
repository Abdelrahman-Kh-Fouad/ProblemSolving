#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    while (cin>>n,n!=0)
    {
        vector<int>arr;
        int minn=INT_MAX;
        for (int i =0 ;i <=31 ;i++)
        {
            for (int j =0 ; j <= 31 ;j++)
            {
                long long  x = pow(2,i)*pow(3,j);
                if (x>INT_MAX)
                    break;
                if (x>=n)
                    minn=min(minn,(int)x);
            }
        }
        cout<<minn<<endl;
    }
    return 0;
}
