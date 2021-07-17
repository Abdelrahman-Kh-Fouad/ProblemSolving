#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

class stat{
public :
    ull up ,down ;
public :
    stat():up(0),down(0){}
    stat(ull up ,ull down ):up(up) , down(down){}
    void cop(stat& other){
        this->up = other.up;
        this->down = other.down;
    } 
    stat operator+ (const stat &other){
        return stat (other.up + this->up , other.down + this->down);
    }
};
void solve()
{
    string s ; 
    cin >>s ; 
    stat  left(0 , 1 ) , right (1 ,0) , cur(1,1);
    for(char i : s ){
        stat tmp; 
        switch (i){
        case 'L':
            right = cur ; 
            break;
        
        case 'R':
            left  = cur ; 
            break;
        }       
        cur = right + left  ; 

    }
    cout << cur.up<<"/"<<cur.down<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;

    while(t--){
        solve();
    }
    return 0 ; 
}