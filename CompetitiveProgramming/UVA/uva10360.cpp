#include <bits/stdc++.h>
#define p pair<int,int>
#define f first
#define s second
using namespace std;
int main()
{
    int t ; cin>>t;
    while (t--)
    {
        int d ; cin>>d;
        int n ;cin>>n;
        int maxx =-1 ,maxy=-1;
        vector<vector<int>>arr(1025 , vector<int>(1025 , 0 ));
        for(int i =0 ;i < n ;i++)
        {
            int x, y ,s ; cin>>x>>y>>s;
            for (int  j = x-d ; j<=x+d && j<=1024; j++)
            {
                if(j<0)continue;
                for (int k =y-d ; k<=y+d && k<=1024; k++)
                {
                    if(k<0)continue;
                    arr[j][k]+=s;
                    maxx=max(j , maxx);
                    maxy=max(maxy ,k );
                }
            }
        }
        int res =-1;
        p point ;
        for (int i =0 ;i <=maxx ; i++)
            for (int j =0 ;j <=maxy ;j++)
                if(res < arr[i][j])
                    res = arr[i][j] , point = {i ,j };

        cout<<point.f <<" "<<point.s<<" "<<res<<endl;
    }
    return 0;
}
