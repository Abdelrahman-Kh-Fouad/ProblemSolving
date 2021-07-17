#include <bits/stdc++.h>
using namespace std ;
long long power (int x ,int y )
{
    long long product =1 ; 
    while(y--)
        product *=x;
    return product ;
}
int main ()
{
    int T ; cin >>T ;
    while(T--)
    {
        int l ;
        vector <int>arr;
        while (cin>>l && l!=0)
            arr.push_back(l);
        sort(arr.begin() ,arr.end(),greater<int>());
        long long sum =0;
        for (int i =1 ;i <= arr.size()&&sum <= 5e6 ;i++)
            sum+=2*power(arr[i-1] , i); 
        if(sum >5e6 )
            cout<<"Too expensive\n";
        else 
            cout<<sum<<"\n";
    }
    return 0 ;
}