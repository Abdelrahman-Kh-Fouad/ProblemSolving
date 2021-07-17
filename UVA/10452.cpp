#include <bits/stdc++.h>
using namespace std;
int xx[]={-1,0,0};
int yy[]={0,-1,1};
map<int ,string >fs;
set <char> my ;

set < pair<int,int > >ch ;
int n ,m ;
pair <int,int >start,endd;
bool f =1;

inline bool valid (pair<int ,int >cur ,vector<vector<char> >&arr)
{
    return (f&&cur.first>=0 && cur.second>=0 && cur.first<n && cur.second<m &&
             my.count(arr[cur.first][cur.second])&& !ch.count(cur));
}
void DFS(vector<vector<char> >&arr,pair<int ,int >cur , string s )
{
    if (valid(cur ,arr))
    {
        ch.insert(cur);
        if (cur == endd)
        {
            f=1;
            s.pop_back();
            cout<<s<<endl;
            return;
        }

        for (int i =0 ; i < 3 ;i++)
            DFS(arr , {cur.first+xx[i] , cur.second +yy[i]}, s+fs[i]+" ");

    }
}
int main()
{
    fs[0]="forth";fs[1]="left";fs[2]="right";
    string ss ="IEHOVA#@";
    my.insert(ss.begin() , ss.end());
    int t ; cin>>t;

    while (t--)
    {
        cin>> n>>m;
        vector<vector<char> >arr(n,vector<char>(m));
        for (int i =0 ;i < n ;i++)
            for (int j=0 ; j <m ;j++)
                {
                   cin>>arr[i][j];
                   if (arr[i][j] == '@')
                    start.first=i,start.second=j;
                   if (arr[i][j]=='#')
                    endd.first=i , endd.second = j;
                }
        DFS(arr,start,"");
        f=1;ch.clear();

    }
    return 0;
}
