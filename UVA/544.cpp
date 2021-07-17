#include<bits/stdc++.h>
using namespace std ;
#define p pair<int ,int >
#define f first 
#define s second 
class dsu {
private :
    vector<int>parent, rank;
public :
    dsu(int n )
    {
        parent.assign(n , 0);
        rank.assign(n,0);
        for(int i =0 ;i < n ;i++)
            parent[i] = i;
    }
    int set_of(int i )
    {
        if(parent[i] == i)
            return i ;
        else 
            return parent [i] = set_of(parent[parent[i]]);
    }
    bool is_same(int i ,int j )
    {
        i = set_of(i) ; j = set_of(j);
        return i== j;
    }
    void Union(int i ,int j )
    {
        i = set_of(i) ; j = set_of(j);
        if(i!=j)
        {

            if(rank[i] < rank[j])parent[i] = j ;
            else 
            {
                parent[j]=i;
                if(rank[i] == rank[j])
                    rank[i]++;
            }

        }

    }


};

bool cmp(pair<p ,int> x ,pair<p ,int> y )
{
    return x.s > y.s;
}
int main ()
{
    int n , m ; 
    int t = 0;
    while(cin>>n>>m && (n || m))
    {
        string a , b ;
        int w ; 
        map<string , int >names ;
        int cntnames =0 ; 
        vector<pair<p ,int>>edges;
        for(int i =0 ;i < m ;i++)
        {
            cin>>a>>b>>w;
            if(!names.count(a))
                names[a]=cntnames++;
            if(!names.count(b))
                names[b]=cntnames++;
            edges.push_back({{names[a] ,names[b]} ,w });
        }
        sort(edges.begin() ,edges.end() ,cmp);cin>>a>>b; 
        int x= names[a] ,y=names[b] ;
        
        dsu ss(n);
        int res= 0; 
        for(auto e :edges )
        {
            int u = e.f.f , v = e.f.s ,w = e.s;
            int tmp = -1  ;  
            if(!ss.is_same(u ,v ))
                ss.Union(u ,v ) ,res =w ;
            if(ss.is_same(x ,y ))
                break ;
            
        }

        // for( auto e: edges)
        // {
        //     int u = e.f.f , v = e.f.s ,w = e.s;
        //     if(ss.is_same(u ,x ) && ss.is_same(v,x))
        //         res = max (res , w );

        // }
        printf("Scenario #%d\n%d tons\n\n" , ++t , res);


    }

}
