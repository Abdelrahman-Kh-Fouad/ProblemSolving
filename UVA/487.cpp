#include <bits/stdc++.h>
#define p pair<int ,int >
#define f first
#define s second
using namespace std;
//fstream f("../s.txt");
int n ;
set<p>ch;
set<string >d;
vector<string> res ;
int xx[]={0,0,-1,1,-1,1,-1,1};
int yy[]={1,-1,0,0,-1,1,1,-1};
inline bool valid (p x )
{
    return (x.s>=0 && x.s<n  && x.f>=0 && x.f<n);
}
void go(vector<vector<char>>&arr , p now ,string &s  )
{
    for (int i =0 ;i < 8 ;i++)
    {
        p ind ={now.f +xx[i],now.s +yy[i]};
        if (!valid(ind))continue;
        if ((int)arr[ind.f][ind.s] > (int)arr[now.f][now.s])
        {
            s.push_back(arr[ind.f][ind.s]);
            if (!d.count(s)&&s.size()>=3)
                res.push_back(s);
            d.insert(s);
            ch.insert(ind);
            go(arr, ind ,s);
            s.erase(s.end()-1);
            ch.erase(ind);
        }
    }
}
bool cmp(string x , string y )
{
    if (x.size()!=y.size())
        return(x.size() < y.size());
    else
        return(x < y );
}
int main()
{
    int t ; cin>>t;
    while (t--)
    {
        cin>>n;
        vector<vector<char>>arr(n,vector<char>(n));
        for (int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        string tmp ;
        for(int i =0 ;i < n ;i++)
            for(int j =0 ;j < n ;j++)
                go(arr,{i,j},tmp.assign(1,arr[i][j]));

        sort(res.begin() ,res.end(),cmp);
        for(auto i : res )cout<<i<<endl;if (t)cout<<endl;
        res.clear();
        d.clear();

    }
    return 0;
}
