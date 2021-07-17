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
vector<vector<int>>arr;
void print()
{
    cout<<"A=>";
    if(arr[0].size())cout<<"   ";
    for(int i= 0 ;i<sz(arr[0]) ;i++)cout<<arr[0][i] , cout<<((i==sz(arr[0])-1) ? "":" ");
    cout<<endl;
    cout<<"B=>";
    if(arr[1].size())cout<<"   ";
    for(int i= 0 ;i<sz(arr[1]) ;i++)cout<<arr[1][i] , cout<<((i==sz(arr[1])-1) ? "":" ");
    cout<<endl;
    cout<<"C=>";
    if(arr[2].size())cout<<"   ";
    for(int i= 0 ;i<sz(arr[2]) ;i++)cout<<arr[2][i] , cout<<((i==sz(arr[2])-1) ? "":" ");
    cout<<endl;
    cout<<endl;
}
int m ,n  ;
int deb =0 ;
void ch (int source ,int dist)
{
    
    int tmp = arr[source].back();
    arr[source].pop_back();
    arr[dist].pb(tmp);
    print();
    deb ++; 
}
void go(int top  ,int source , int aux, int dist  )
{
  if (deb == m)
        return;

    if (top== 1)
        ch(source , dist);
    else
    {
        go(top - 1, source, dist, aux);
        if (deb == m)return;
        ch(source,dist);
        go (top - 1, aux, source, dist);
    }

}
void solve()
{
    deb = 0 ;
    arr.assign(3,vector<int>());
    for(int i =n ;i >=1 ;i-- )
        arr[0].pb(i);
    print();
    go(n , 0 ,1 ,2);
}
int tt= 0 ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>n >>m&& (n || m ))
    {
        cout<<"Problem #"<<++tt<<"\n\n" ; 
        solve();
    }
    return 0 ; 
}