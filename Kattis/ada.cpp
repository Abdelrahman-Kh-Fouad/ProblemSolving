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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ; cin>>n ;
    vector<int>arr(n);
    for(int &i : arr)cin>> i ;
    int end =arr.back();

    set<int>ch(all(arr));
    int d =0 ; 
    int sum = 0;
    while(sz(ch) >1 )
    {
        d++ ;
        vector<int>next;
        for(int i =0 ;i < sz(arr)-1 ;i++)
            next.pb(arr[i+1]-arr[i]);
        sum += next.back();

        arr.assign(all(next));
        ch = set<int>(all(arr));
        
    }
    cout<<d  <<" "<< end+sum <<endl; 
    return 0 ; 
}

    