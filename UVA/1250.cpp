#include<bits/stdc++.h>
using namespace std ;
vector<pair<pair<int,int> ,int >> points;
double  memo[1001][1001];
double dp(int ind =1,int prev=0  )
{
    int newx= points[ind].first.first;
    int newy= points[ind].first.second;
    int prevx= points[prev].first.first;
    int prevy= points[prev].first.second;

    if(ind == points.size()-1)
        return sqrt((newx-prevx) * (newx-prevx) + (newy-prevy)*(newy-prevy)) +1 ; 
    double stat = memo[ind][prev];
     if(!isnan(stat) )
         return stat;
    double leave = dp(ind+1 , prev ) + points[ind].second;


    double take = dp(ind+1 , ind)  + 1 +sqrt((newx - prevx )*(newx - prevx ) + (newy-prevy)*(newy-prevy))  ;
    memo[ind][prev] = min (take ,   leave );
    return min (take ,   leave );
} 
int main()
{
    int n ; 
    while(cin>>n && n !=0)
    {
        int x,y,p;
        points.clear();
        points.push_back({{0,0} , 0 });
        for(int i =0 ;i < n ;i++)
            cin>>x >>y >> p, points.push_back({{x,y} , p }) ;
        points.push_back({{100,100} , 0 });
        memset(memo , -1 , sizeof memo);
        printf("%0.3f\n" ,dp());
    }
    return 0 ;
}