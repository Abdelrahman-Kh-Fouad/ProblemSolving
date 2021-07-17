#include<bits/stdc++.h>
using namespace std ; 
int main(int argc, const char** argv) {
    int n , m;
    while (cin>>n>>m&& (n &&m))
    {
        int dragons[n] , knights[m];
        for (int i =0 ;i < n ;i++)
            cin>>dragons[i];
        for (int j=0 ;j< m ;j++)
            cin>>knights[j];
        sort(knights , knights+m);
        sort(dragons ,dragons+n);
        if(n>m )
            cout<<"Loowater is doomed!"<<endl;
        
        else 
        {
            int sum =0 ;
            int i , j ;
            for (i =0 , j =0 ; i < n && j<m ;)
            {
                if(knights[j]>=dragons[i])
                    sum +=knights[j++],i++;   
                else j++;
            }
            if (sum && i==n)
                cout<<sum<<endl;
            else 
                cout<<"Loowater is doomed!"<<endl;
        }
    }
    
    return 0;
}