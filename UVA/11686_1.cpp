#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int n,m ;
    while (cin>>n>>m , n||m)
    {
        vector<vector<int>> adj(n+1);
        int a , b ;
        for (int i =0 ;i < m ;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
        }
        vector<int>degree(n+1 , 0 );
        vector<bool>used(n+1 , 0 );
        for (int i =1 ; i <=n ;i++)
            for(auto j : adj[i])
                degree[j]++;
        queue<int>q;
        for (int i=1 ;i <=n ;i++)
            if (!degree[i]) q.push(i),used[i]=1;
        vector<int>res;
        bool f =1 ;
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            res.push_back(tmp);
            for(auto i : adj[tmp])
            {
                if (!used[i])
                {
                    if (! (--degree[i]))
                        q.push(i),used[i]=1;
                }
            }
        }
        for(auto i : degree)
            if(i!=0)
                f=0;
        if (f )
            for(auto i : res)
                cout<<i<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
