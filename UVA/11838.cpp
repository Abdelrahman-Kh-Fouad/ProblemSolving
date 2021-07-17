#include <bits/stdc++.h>
using namespace std ;
vector<bool >used ;
stack<int>element;
void dfs(vector<vector<int>>&adj , int node ,bool f =1 )
{
    used[node]=1;
    for(auto i : adj[node])
        if(!used[i])
            dfs(adj , i,f);
    if(f)
        element.push(node);
}
int main() {
    int n ,m ;
    while(cin>>n>>m , n!=0 && m!=0)
    {
        vector<vector<int>> adj(n+1) ;vector<vector<int>> adjR(n+1);
        int from , to , val ;
        for (int i =0 ;i < m ;i++)
        {
            cin>>from>>to>>val;
            if(val==1)
                adj[from].push_back(to) ;
            else
                adj[from].push_back(to),
                adj[to].push_back(from);

        }

        for(int i =1 ; i <= n ;i++)
            for(auto j : adj[i])
                adjR[j].push_back(i);


         used.assign(n+1,false);
        for(int i =1 ;i <=n ;i++)
            if(!used[i])dfs(adj , i );


        used.assign(n+1,false);
        int cnt =0;
        while (!element.empty())
        {
            int tmp = element.top();
            element.pop();
            if(!used[tmp])
                dfs(adjR , tmp,0),cnt++;
        }
        if(cnt>1)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}