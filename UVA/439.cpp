#include <bits/stdc++.h>
using namespace std ;
//ifstream in ("../in.txt");
//ofstream out ("../out.txt");
int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

int d[8][8];
vector <int >ss;
int bfs (int sr ,int sc ,int er , int ec)
{
    memset (d, -1 , sizeof(d));
    d[sr][sc]=0;
    queue<int>q;
    q.push(sr);q.push(sc);
    while (!q.empty())
    {
        int r = q.front();q.pop();
        int c = q.front();q.pop();
        if (er==r && ec ==c) return d[r][c];
        for (int k =0 ;  k< 8 ; k++)
        {
            int nr = r+dx[k];
            int nc = c+dy[k];
            if (!(nr >=0 && nr<=7 && nc >=0 && nc <=7))
                continue;
            if (d[nr][nc]==-1)
            {
                d[nr][nc]=d[r][c]+1 ;
                q.push(nr);q.push(nc);
            }
        }
    }
    return  -1;
}
int main ()
{
    string _1,_2;
    while (cin>>_1>>_2 )  {
        cout<<"To get from " <<_1 <<" to "<<_2<< " takes "<< bfs((int) (_1[0] - 'a'), (int) (_1[1] - '0') - 1, (int) (_2[0] - 'a'), (int) (_2[1] - '0') - 1) <<" knight moves."<<endl;
    }

    return 0;
}