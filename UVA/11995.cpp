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

int n; 
void solve()
{   
    vector<pair<int,int>>arr(n);
    for(int i =0 ;i < n ;i++)cin>>arr[i].ff >>arr[i].ss;
    priority_queue <int>pr ; 
    queue<int>q ;
    stack <int>st ;
    bool qq =1 ,stt =1 , prr=1; 
    for(auto i : arr )
    {
        switch (i.ff)
        {
        case 1 :
            st.push(i.ss);
            q.push(i.ss);
            pr.push(i.ss);

            break;
        
        default:
            stt &=(!st.empty()) ? i.ss ==st.top() : 0;
            prr &=(!pr.empty()) ? i.ss ==pr.top() : 0;
            qq &=(!q.empty()) ? i.ss ==q.front() : 0;

            if(!st.empty())st.pop();
            if(!pr.empty())pr.pop();
            if(!q.empty()) q.pop();
            break;
        }
    }
    if(qq && !stt && !prr) cout<<"queue"<<endl;
    else if(!qq && stt && !prr)cout<<"stack"<<endl;
    else if(!qq && !stt && prr)cout<<"priority queue"<<endl;
    else if(!qq && !stt && !prr)cout<<"impossible"<<endl;
    else cout<<"not sure"<<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>n )
    {
        solve();
    }
    return 0 ; 
}