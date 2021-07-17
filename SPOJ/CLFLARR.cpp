#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n , m ; cin>>n >>m ;
    vector<vector<pair<int, ll >>>point(n+1 , vector<pair<int, ll>>() );
    vector<ll>res(n , 0 );
    int priority =0; 

    for(int i =0 ;i < m ;i++ , priority++){
        int l,r;
        ll c ; cin>>l >>r>> c ; 
        point[l-1].push_back({priority ,c});
        point[r].push_back({priority ,-c});
    }

    map<int ,ll >color;
    
    for(int i = 0 ;i < n ;i ++){
        vector<pair<int , ll >> cur_v = point[i];

        for(auto &el : cur_v){
            if(el.ss > 0 ){
                color.insert(el);
            }
            else if(el.ss < 0){
                color.erase(el.ff);
            }
        } 
        if(color.size())
            res[i] = (*color.rbegin()).ss;
   
    }
    for(ll &i : res )
        cout <<i <<endl;
    
    return 0 ; 
}