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
bool bs (vector<int>& arr , int tar )
{
    int l =0 , r = arr.size()-1;
    int mid ; 
    while(l<= r)
    {
        mid = l + (r-l)/2 ;
        if(arr[mid] == tar)return 1 ;
        if(arr[mid] > tar ) r = mid -1 ;
        else  l= mid+1 ;
    }
    return 0;
}
void solve()
{
    ll n, m ,a,c ,x0 ;
    cin>>n >>m >>a >>c >>x0 ;
    vector<int>seq ; 
    unordered_map<int ,int >mp ; 
    seq.pb((((a * x0 + c)%m)+ m)%m  );
    mp[seq[0]]++;
    for(int i =1 ; i <n ;i++)
        seq.pb((((a * seq[i-1] + c)%m)+ m)%m  ) , mp[seq[i]]++;
    int cnt =0 ; 
    for(auto &i :mp)
    {
        if(bs(seq , i.ff) )
            cnt +=i.ss ; 
    }
    cout<<cnt<<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


        solve();
    
    return 0 ; 
}