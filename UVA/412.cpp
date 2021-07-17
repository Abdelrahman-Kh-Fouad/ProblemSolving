#include <bits//stdc++.h>
using namespace std ;

int main() {
    int n;
    pair<int ,int > temp1,temp2;

    while (1)
    {
        set <pair<int,int>>com;
        cin >>n;
        if(n==0)
            return 0;

        int arr[n];
        for (int i =0 ;i <n ;i++)
            cin >>arr[i];

        int set=0;
        for (int i =0 ;i < n;i++)
        {
            for (int j =0 ;j<n ;j++)
            {
                if (j==i)
                    continue;

                temp1=make_pair(i,j);
                temp2=make_pair(j,i);
                if (!(com.count( temp1) || com.count(temp2)))
                {
                    com.insert(temp1),set++;

                }
            }
        }

        int sum =0 ;
        for (auto i :com)
        {

            if (__gcd(arr[i.first],arr[i.second]) ==1)
                sum++;
        }

        if (sum==0)
            cout<<"No estimate for this data set."<<endl;
        else
            cout<<fixed<<setprecision(6)<<sqrt(6*((double)set/sum))<<endl;

    }
    return 0;
}
