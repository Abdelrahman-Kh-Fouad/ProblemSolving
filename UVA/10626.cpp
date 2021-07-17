    #include<bits/stdc++.h>
    using namespace std ;
    int n ,n1 ,n5,n10;
    int memo[151][101][51];

    int oo=1e9;
    int total ;
    int dp(int res  ,int curn1,int curn5 ,int curn10 )
    {
        if(res > n)
            return oo ;
        if(res == n)
            return memo [res][curn5][curn10] = 0 ;

        int &stat = memo[res][curn5][curn10];
        if(stat !=-1)
            return stat ;

        int ch1= oo,ch2=oo , ch3=oo, ch4 =oo,ch5=oo  ;
        curn1 = total - 8*res - curn5*5 - curn10*10;
        if(curn10>0)
            ch1=dp(res+1 , curn1+2 , curn5 ,curn10 -1 )+1;
        if(curn5>=2)
            ch2=dp(res+1 , curn1 +2, curn5-2 ,curn10  )+2 ;
        if(curn5>0 && curn1>=3)
            ch3=dp(res+1  , curn1-3 , curn5-1 ,curn10  )+4;
        if(curn10 >0&& curn1>=3)
            ch4=dp(res+1 ,curn1-3 , curn5+1,curn10 -1 )+4;
        if(curn1>=8)
            ch5=dp(res+1 ,curn1-8 , curn5 ,curn10 )+8 ;


        int product = min(min(min(ch1 , ch2 ) ,min (ch3 ,ch4)), ch5 );  
        memo [res] [curn5] [curn10] =product;
        return product ;
    }
    int main ()
    {
        int t ; cin>>t ;
        while(t--)
        {
            cin>>n>>n1>>n5>>n10;
            total=n1 + n5*5 +n10*10;
            memset(memo , -1 , sizeof memo);
            cout<<dp(0 , n1,n5,n10)<<"\n";
        }
    }