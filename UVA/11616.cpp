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

string s ; 
unordered_map<string,int> char_to_int;
vector<int>arabic ;
vector<string>rom ; 
vector<int>frg(int num ){
    vector<int>res ;
    int cnt =0 ; 
    while(num){
        res.pb((int)pow(num %10 , cnt++));
        num /=10;
    }
    return res ;
}
void solve(){
    if(isdigit(s.front())){
        int num  = stoi(s);
        string res ="";
        int ind = 12;
        while(num){
            while(arabic[ind] > num)ind--;
            res +=rom[ind];
            num-=arabic[ind];   
        }
        cout <<res <<endl;
    }   
    else {
        int res =0 ; 
       for(int i = 0 ;i <sz(s) ;i++){
            if(i!= sz(s) -1 ){
                string tt = s.substr(i , 2 );
                if(char_to_int.count(tt)){
                res += char_to_int[tt];
                i++ ;
                continue;
                }
            } 
        
        string t = s.substr(i ,1 );
        res +=char_to_int[t];
           
       }
        cout <<res <<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    rom = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    arabic={1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    for (int i =0 ;i <sz(rom) ;i++){
        char_to_int[rom[i]] = arabic[i];
    }

    while(getline(cin ,s )){
        solve();
    }
    return 0 ; 
}