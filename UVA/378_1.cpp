#include <bits/stdc++.h>
#define oo 10000000000;
using namespace std ;
typedef pair<double,double> point ;
typedef struct{
    double a,b,c,vector;
    point onit;

}line;
void get_equ(line *temp )
{
    if (temp->vector == (double)10000000000)
    {
        temp->a=0;
        temp->b=1;
        temp->c =temp->onit.second;
    }
    else
    {
        temp->a=1;
        temp->b=-temp-> vector;
        temp->c=-temp->vector *temp->onit.second + temp-> onit.first;
    }

}
bool parallel (line x , line y )
{
    if (x.vector==y.vector)
        return  1;
    else
        return  0;
}
bool same (line x , line y )
{
    if (parallel(x,y))
    {
        if ( x.onit.first*y.a + x.onit.second*y.b ==y.c)
            return 1;
        else
            return  0;
    }
    else
        return  0;
}
point solve (line x,line y)
{
    return make_pair(
            ((x.c*y.b - x.b*y.c)/(x.a*y.b - x.b* y.a ))
            , ((x.a*y.c - x.c * y.a) /(x.a*y.b - x.b* y.a))
    );
}
int main() {

    int n ; cin>>n;
    cout<<"INTERSECTING LINES OUTPUT\n";
    int x1,y1,x2,y2;
    while (n--)
    {

        cin>>x1>>y1>>x2>>y2;
        line line1;
        line1.vector=(y1-y2!=0)?(double)(x1-x2)/(y1-y2) : oo;;
        line1.onit={x1,y1};
        cin>>x1>>y1>>x2>>y2;
        line line2;
        line2.vector=(y1-y2!=0)?(double)(x1-x2)/(y1-y2) : oo;
        line2.onit={x1,y1};
        get_equ(&line1);get_equ(&line2);
        if (parallel(line1,line2)  && !(same(line1,line2)))
            cout<<"NONE"<<endl;
        else
            if (same(line1,line2))
                cout<<"LINE"<<endl;
            else
                cout<<fixed<<setprecision(2)<<"POINT "<<solve (line1,line2).first<<" "<<solve(line1,line2).second<<endl;

    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
