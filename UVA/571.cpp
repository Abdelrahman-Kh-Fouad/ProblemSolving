#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;


int  ac , bc , n ;
int  vis[1001][1001];
map<int ,string>conv ;
class Node {
public:
    int a , b;
    int op ; 
    Node * parent;
public :
    Node(int a , int b ,int op, Node *parent):a(a),b(b),op(op),parent(parent){}
};
inline vector<pair<int,int>>val(int a , int b ){
    return  { {ac, b},{a , bc}
    ,{0 , b },{a, 0 }
    ,{min (a + b , ac) , max( b - (ac -a ) , 0 )}
    ,{max(  a - (bc - b ), 0 ),  min (a + b , bc) }};
}

void solve()
{
    memset(vis , 0 ,sizeof vis);

    queue<Node*>q ;
    Node *res=nullptr ;
    q.push(new Node(0 , 0 , -1 , nullptr)); 
    while(sz(q)){
        Node *cur = q.front();
        q.pop();
        vector<pair<int,int>>next = val(cur->a , cur->b);
        for(int k =0 ;k < sz(next) ;k++){
            
            auto i = next[k];
            if(!vis[i.ff ][i.ss])
                vis[i.ff][i.ss]=1 , q.push(new Node(i.ff , i.ss , k , cur));
        }
        if(cur->b == n  ){
            res = cur ;
            break;
        }

    }

    vector<string>out ; 
    while(res != nullptr){
        if(res->op != -1 )
            out.pb(conv[res->op]);
        res = res->parent;
    }
    reverse(all(out));
    for(auto &i:out)
        cout << i <<endl;
    cout <<"success"<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    conv[0] = "fill A";
    conv[1] = "fill B";
    conv[2] = "empty A";
    conv[3] = "empty B";
    conv[4] = "pour B A";
    conv[5] = "pour A B";

    while(cin>>ac >> bc >> n ){
        solve();
    }
    return 0 ; 
}