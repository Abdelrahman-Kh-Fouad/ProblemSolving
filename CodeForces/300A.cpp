#include <bits/stdc++.h>
using namespace std ;
int main() {
    int n ; cin>>n;
    vector<int>ne , po,ze ;
    int zeros =0 , tmp;
    for (int i =0 ;i < n ;i++)
    {
        cin>>tmp;
        if(tmp==0)zeros++;
        if (tmp > 0 )po.push_back(tmp);
        if (tmp < 0 )ne.push_back(tmp);
    }

    if (ne.size() % 2==0) {
        ze.push_back(ne.back());
        ne.pop_back();
    }
    if(!(ne.size() && po.size()))
    {
        if (!po.size() && ne.size()>2)
        {
            po.push_back(ne.back());
            ne.pop_back();
            po.push_back(ne.back());
            ne.pop_back();
        }

    }
    cout << ne.size()<<" ";
    for (auto i : ne)cout<<i<<" ";cout<<endl;
    cout << po.size()<<" ";
    for (auto i : po)cout<<i<<" ";cout<<endl;
    cout<<zeros+ze.size()<<" ";
    for (int i =0 ;i < zeros ;i ++)
        cout<<0<<" ";
    for (auto i : ze )cout<<i<<" ";
    return 0;
}
