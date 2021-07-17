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
string in ; 


string print(vector<int>&num , vector<char>&op , string& res )
{
    stringstream s("") ; 
    int i =0 ; 
    for(;i<sz(op);i++)
        s<<num[i]<<" " << op[i]<< " ";
    s<<num.back()<<" "<<"= "<<res;
    return s.str();
}
void solve()
{
    vector<int>num ; 
    vector<char>op;
    string res ;
    stringstream ss (in);
    bool tog =1 ; 
    while (1)
    {   
        if(tog)
        {
            int tmp ; ss>>tmp; 
            num.pb(tmp);
        }
        else 
        {
            char tmp ; ss>>tmp;
            if(tmp == '=')
                break; 
            op.pb(tmp);
        }
        tog ^=1 ;
    }
    ss>>res ;
    cout<< print(num , op , res )<<endl;
    bool f =1 ;
    while(f)
    {
        f= 0; 
        for(int ind =0 ; ind < sz(op) ;ind++)
        {
            int tmp ; 
            if(op[ind]== '/' || op[ind]=='*')
            {
                f=1 ;
                if(op[ind]=='/')
                    tmp = num[ind] / num[ind+1];
                else 
                    tmp = num[ind] * num[ind+1];
                num.erase(num.begin() +ind+1 );
                num[ind]=tmp ;
                op.erase(op.begin() + ind );
                cout<< print(num , op , res )<<endl;
                break;
            }
        }
    }
    f=1 ;
    while(f)
    {        
        f= 0 ;

        for(int ind =0 ; ind < sz(op) ;ind++)
        {
            int tmp ; 
            if(op[ind]== '+' || op[ind]=='-')
            {
                f=1 ; 
                if(op[ind]=='+')
                    tmp = num[ind] + num[ind+1];
                else 
                    tmp = num[ind] - num[ind+1];
                num.erase(num.begin() +ind+1 );
                num[ind]=tmp ;
                op.erase(op.begin() + ind );
                cout<< print(num , op , res )<<endl;
                break;
            }
        }
    }
    cout<<endl;

}   
int main()
{
    // freopen("in" , "r" , stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(getline(cin , in))
    {
        solve();
    }
    return 0 ; 
}