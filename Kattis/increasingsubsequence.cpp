#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
 
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.ff << ", " << p.ss << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    for(int i =0; i< sz(v) ; i++) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}
typedef long long ll;
typedef unsigned long long ull;
int n ; 
int memo [201][201];
int dp(vector<int>&arr ,  int prev ,int cur)
{
    if(prev < 0 )return 1;
    int &stat =memo[prev][cur];
    if(stat !=-1)return stat ; 
    int ch1 = dp(arr ,prev -1  , cur );
    int ch2 = 0 ;
    if(arr[cur] > arr[prev]) ch2 = dp(arr ,prev -1  ,prev ) +1 ;
    return stat = max(ch1 ,ch2 );
}
void solve()
{
    vector<int>arr(n);
    for(int i =0 ;i < n ;i++)
        cin>>arr[i];
    memset(memo , -1 , sizeof memo );
    vector<int>res(n) ,out;
    for(int i = n-1 ; i >=0 ; i-- )
        res[i]=dp(arr , i-1 ,i );

    int pos = max_element(all(res)) -res.begin();
    int tosearch = res[pos];
    pos = n-1 ;
    cout<< tosearch <<" ";
    while(tosearch > 0 )
    {
        int minn = INT_MAX , ind = -1 ;
        for(int i =0 ;i <=pos ;i++ )
        if(res[i] == tosearch && arr[i] < minn )    
            minn =arr[i] ,ind = i ;
        out.pb(arr[ind]);
        tosearch--;
        pos = ind ;
    }
    reverse(all(out));
    for(int &i : out)cout<<i<<" ";
    cout<<endl;

    // vector<int>lis(n,1) ,go(n , -1 );
    // vector<int>res ; 
    // for(int i =1 ; i < n ; i++)
    // {
    //     for(int j =i-1 ; j >=0 ; j--)
    //     {
    //         if(arr[i] > arr[j] && lis[j]+1 > lis[i] )
    //             lis[i] = lis[j]+1 , go[i]= j ;
    //         else if(lis[i] == lis[j] +1 && arr[go[i]] > arr[j])
    //             go[i] = j ; 
    //     }
    // }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in" , "r" ,stdin);
    while(cin>>n &&n!=0 )
        solve();    
    return 0 ; 
}   