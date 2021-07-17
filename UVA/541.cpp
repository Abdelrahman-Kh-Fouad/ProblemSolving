#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int n ;
    while (1)
    {
        cin>>n;
        if (n==0)
            return 0;
        int arr[n][n];
        int row [n] ,col [n];
        memset(row , 0 ,sizeof (row));
        memset(col , 0 ,sizeof (col));

        for (int i =0 ;i< n ; i++)
            for (int j =0 ;j<n ;j++)
                cin>>arr[i][j];

        for(int i =0 ; i<n ;i++)
        {
            int cnt =0;
            for (int j =0 ; j< n ;j++)
            {
                cnt+=arr[i][j];
            }
            if (cnt %2 !=0)
            {
                row[i]++;
            }
        }
        for(int i =0 ; i<n ;i++)
        {
            int cnt =0;
            for (int j =0 ; j< n ;j++)
            {
                cnt+=arr[j][i];
            }
            if (cnt %2 !=0)
            {
                col[i]++;
            }
        }
        int x ,y ,cntx=0,cnty=0;
        for (int i =0; i< n ;i++)
        {
            if (row[i] ==1 )
                x=i+1,cntx++;
            if (col[i]==1)
                y=i+1,cnty++;

        }
        if (cntx==1 && cnty==1)
        {
            cout<<"Change bit ("<<x<<","<<y<<")"<<endl;
        }
        else if (cntx==0 && cnty ==0)
        {
            cout<<"OK"<<endl;
        }
        else
        {
            cout<<"Corrupt"<<endl;
        }
    }
    return 0;

}