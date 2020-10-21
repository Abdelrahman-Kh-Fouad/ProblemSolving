#include <bits/stdc++.h>
using namespace std ;
vector<int>res ;
vector<int>tmp;
int maxx =-1;
int sum ;
void go (vector<int>&arr , int ind ,int s )
{

    if(s > sum)
        return;
    if(ind==arr.size())
    {
        if(s>maxx )
        {
            maxx=s ;
            res.assign(tmp.begin() ,tmp. end() );
        }
        return;
    }
    tmp.push_back(arr[ind]);
    go(arr , ind+1 , s+arr[ind]);
    tmp.pop_back();
    go(arr , ind+1 , s);
}
int main() {
    int  n ;
    while(cin>>sum>>n)
    {
        vector<int>arr(n);
        for(int i =0 ;i < n ;i++)
            cin>>arr[i];
        go(arr , 0,0);
        for(auto i : res )cout<<i<<" ";
        cout<<"sum:"<<maxx<<endl; ;
        maxx=-1;

    }
    return 0;
}
