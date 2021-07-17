#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n ; cin>>n;
    int prev =-1 , prev_sum =0 ;
    int  cur = 0 , cur_sum  =0 ;
    int tmp; 
    cin>>tmp; cur = tmp ,cur_sum++;
    int size = 1 ;
    for(int i =1 ;i< n; i++)
    {
        cin>>tmp; 
        if(tmp == cur  )cur_sum++;
        else if(tmp == prev  )
        {
            prev_sum +=cur_sum ;
            prev= cur ; 
            cur_sum=1;
            cur = tmp; 
        }
        else if(abs (tmp - cur) <=1)
        {
            prev =cur ; 
            prev_sum =cur_sum;
            cur_sum=1; cur =tmp;
        }
        else
        {
            prev =-1 ; 
            prev_sum=0 ;
            cur=tmp;
            cur_sum=1;
        } 
        size =max(size , cur_sum +prev_sum);
    } 
    cout<<size<<endl;
}

