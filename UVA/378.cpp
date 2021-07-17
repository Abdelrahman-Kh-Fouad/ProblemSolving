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


const double PI  =2 * acos(0);
class Point{
public:
    double x , y ;
public: 
    Point():x (0), y(0){}
    Point(double x ,double y ):x(x),y(y){}
    bool operator < (Point other)const {
        if(fabs(x-other.x) > 1e-6)
            return x < other.x ;
        else    
            return y < other.y;
    } 
    bool operator == (Point other )const {return (fabs(other.x - x )< 1e-6 && fabs(other.y - y )< 1e-6);}
};

class Line {
public :
    double a , b , c ; 
public : 
    Line ():a(0) ,b(0) ,c(0){}
    Line(Point p1 , Point p2 ){
        if(fabs(p1.x - p2.x) <1e-6)
            a = 1 , b = 0 , c = -p1.x;
        else{
            a = -(p1.y -p2.y)/(p1.x - p2.x) ; 
            b =1 ; 
            c = -(a * p1.x )-p1.y;
        } 
    }
};

bool areParallel(Line l1 , Line l2 ){
    return (fabs(l1.a - l2.a) <1e-6 && fabs(l1.b - l2.b) <1e-6  );
}
bool areSame(Line l1 ,Line l2){
    return areParallel(l1 , l2 )&& fabs(l1.c - l2.c) < 1e-6; 
}
pair<bool, Point> areIntersect(Line l1 , Line l2){
    if(areParallel(l1 ,l2 )) return {0 ,Point()};
    Point res;
    res.x = (l2.b *l1.c -l1.b * l2.c) / (l2.a*l1.b -l1.a *l2.b);
    if(fabs(l1.b) > 1e-6)
        res.y = -(l1.a *res.x +l1.c);
    else 
        res.y = -(l2.a *res.x +l2.c);
    return {1 , res };
}

void solve(){
    int x1 ,y1 , x2 ,y2 ,x3 ,y3 , x4 ,y4;
    cin>>  x1 >>y1 >> x2 >>y2 >>x3 >>y3 >> x4 >>y4; 
    Line l1(Point(x1 , y1 ) , Point(x2 , y2 ));
    Line l2(Point(x3 , y3 ) , Point(x4 , y4 ));
    pair<bool , Point> res =areIntersect(l1 , l2 ); 
    if( res.ff){
        cout << "POINT "<<fixed <<setprecision(2)<<res.ss.x <<" "<<res.ss.y<<endl;
    }
    else {
        if(areSame(l1 ,l2 )){
            cout <<"LINE"<<endl;
        }
        else 
            cout <<"NONE"<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    cout <<"INTERSECTING LINES OUTPUT"<<endl;
    while(t--)
    {
        solve();
    }
    cout <<"END OF OUTPUT"<<endl;
    return 0 ; 
}