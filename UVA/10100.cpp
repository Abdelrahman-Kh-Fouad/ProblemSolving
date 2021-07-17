#include<bits/stdc++.h>
using namespace std ;
int memo[1001][1001];
vector<string> a ,b ;
int dp(int i=0 , int j=0 )
{
    if(i==a.size() || j==b.size())
        return 0;
    int &stat = memo[i][j];
    if(stat !=-1)return stat ;
    if(a[i]==b[j])
        return stat = dp(i+1 , j+1 )+1 ;
    
    return stat = max(dp(i+1 ,j) ,dp(i,j+1 )); 
}
int main()
{
    //freopen("in" ,"r",stdin);
    int k =1 ;
    string tmp1 , tmp2 ;
    while(getline(cin ,tmp1 ) && getline(cin,tmp2))
    {
                printf("%2d. ",k++);
          if(tmp1 == "" || tmp2 == "")
        {
            cout<<"Blank!"<<endl;
            continue;
        }
        string tmp3 ="";
        for(int i =0  ; i <= tmp1.size(); i++ ) 
            if(isalpha(tmp1[i]) || isdigit(tmp1[i]))
                tmp3+=((tmp1[i])) ;
            else if(tmp3!="")
                a.push_back(tmp3),tmp3 ="";
        
        for(int i =0  ; i <= tmp2.size(); i++ ) 
            if(isalpha(tmp2[i]) || isdigit(tmp2[i]))
                tmp3+=((tmp2[i]));
            else if(tmp3!="") 
                b.push_back(tmp3),tmp3 ="";



        memset(memo , -1 , sizeof memo);
        cout<<"Length of longest match: "<<dp()<<endl;
        a.clear() ; b.clear();
    }   
    return 0; 
}
