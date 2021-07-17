#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;

class stat {
public :
    ll up , down ; 
    stat():up(0),down(0){}
    stat(ll up ,ll down):up(up),down(down){}
    
    stat operator+ (const stat &other){
        return stat(other.up + up , other.down +down);
    }
    void cop(stat other){
        up = other.up , down = other.down;
    }
    double val (){
        return (double)up/down;
    }

};
void solve(ll m , ll n ){
    string s ="";
    stat cur(1, 1) , r(1 , 0) , l (0 ,1);
    while(cur.up != m || cur.down != n  ){
       
        if(cur.val() > (double)m/n){
            r =cur ; 
            cur = (l+ r) ;
            s+="L";
        }
        else {
            l = (cur) ; 
            cur = (l+ r) ;
            s+="R";
        } 
    }
    cout <<s <<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll m , n ; 
    while( 1 )
    {
        string tmp ; 
        getline(cin ,tmp);
        stringstream ss (tmp);
        ss>> m >> n ;
        if(m ==1 && n ==1 )break;
        solve(m ,n );
    }
    return 0 ; 
}