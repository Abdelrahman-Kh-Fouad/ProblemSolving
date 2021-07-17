#include <bits/stdc++.h>
#define f first
#define s second
#define pp pair<double ,double >
using namespace std;
vector<int>used;
void go (vector<vector<int>>&adj , int node ,int color )
{
    if(used[node]==-1)
    {
        used[node]=color;
        for(auto i :adj[node])
            go(adj , i,color);
    }

}
double dist (pp one ,pp two)
{
    return sqrt((one.f - two.f )*(one.f - two.f ) +
            (one.s - two.s )*(one.s - two.s ));
}
int main()
{
    int t ;cin>>t;
    int tcnt =0;
    while(++tcnt<=t)
    {

        int n ; double d ;
        cin>>n>>d;
        used.assign(n,-1);
        vector<pp>arr(n);
        pp p;
        for (int i =0 ;i <n ;i++)
        {
            cin>>p.f>>p.s;
            arr[i]=p;
        }
        vector<vector<int>>adj(n);
        for(int i =0 ;i < n ;i++)
        {
            for(int j =i+1 ;j < n ;j++)
            {
                if(i==j)
                    continue;
                if(dist(arr[i],arr[j]) -d <=0.0000000001 )
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n ;i++)
            go(adj , i ,i+1 );
        int num[n+1]={0};
        for(int i=0 ;i<n ;i++)
            num[used[i]]++;
        int cnt =0;
        for(int i =1 ;i < n+1; i++ )
            if(num[i]>0)
                cnt++;
        cout<<"Case "<<tcnt<<": "<<cnt<<endl;
    }
    return 0;
}
