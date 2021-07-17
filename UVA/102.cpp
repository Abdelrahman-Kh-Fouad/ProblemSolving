#include <bits/stdc++.h>
using namespace std;
int main()
{
    string line ;
    vector<vector<int>>com;
    for (int i =0 ;i < 3 ;i++)
        for (int j=0 ; j <3 ; j++ )
            for (int k =0 ;k < 3 ;k++)
                if (i!= j && j!=k && i!=k)
                    com.push_back(vector<int>{i,j,k});
    map<int,string>conv{{0,"B"},{1,"G"},{2,"C"}};

    while (getline(cin,line))
    {

        stringstream s (line) ;
        vector<pair<int,string>>final;
        vector<vector<int>>arr(3,vector<int>(3,0));
        for (int c =0 ;c < 9 ;c++)
            s>>arr[c/3][c%3];
        for (auto v : com)
        {
            int sum =0 ;
            for (int i =0 ;i < 3 ;i++)
                sum+=arr[(i+1)%3 ][v[i]]+ arr[(i+2)%3][v[i]];
            string tmp=conv[v[0]]+conv[v[1]]+conv[v[2]];
            final.push_back({sum,tmp});
        }

        pair<int ,string>res =*min_element(final.begin(),final.end());
        cout<<res.second<<" "<<res.first<<endl;

    }
    return 0;
}

