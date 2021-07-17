#include <bits/stdc++.h>
using  namespace std;
int get_bit (unsigned int num , int bit)
{
    return (((1<<bit) & num )> 0 )? 1 :0;
}
void set_bit(unsigned int *num , int bit )
{
    *num |= (1<<bit) ;
}
int main ()
{
    unsigned int x ;
    while (1)
    {

        cin >> x;
        if (!x)
            return 0;
        unsigned  int a=0,b=0;
        int cnt=1;
        for (int i =0 ;i <32 ;i++)
        {
            if (!get_bit( x , i))
                continue;
            else
            {
                if (cnt%2==0)
                    set_bit(&b,i);
                else
                    set_bit(&a,i);
                cnt++;
            }
        }
        cout<<a<<" "<<b<<endl;

    }
    return 0;
}