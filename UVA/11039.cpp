#include<bits/stdc++.h>
using namespace std ;
bool cmp (int x, int y )
{
    return x>y;
}
int main ()
{
    int p ; cin>>p ; 
    while(p--)
    {
        int n ; cin>>n; 
        vector<int>pos , neg; 
        int tmp ; 
        for (int i =0 ;i < n ;i++)
        {
            cin>>tmp ;
            if(tmp < 0 )neg.push_back(-tmp);
            else pos.push_back(tmp);
        }
        sort(pos.begin(), pos.end() ,cmp );
        sort(neg.begin(), neg.end() ,cmp );
        int l =0 ,r=0;
        int cnt =0 ; 
        bool f =(pos[l] > neg[r])?1 : 0;
        while (l < pos.size() && r<neg.size())
        {
            if(pos[l] > neg[r])
            {
                if(f)
                {
                    l++ ;cnt++;f^=1;
                }
                else 
                    l++;
            }
            else 
            {
                if(!f)
                {
                    r++ ; cnt++ ; f^=1;
                }
                else 
                    r++;
            }
        }
        cout<<cnt+1<<endl;
    }
}