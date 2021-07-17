#include <bits/stdc++.h>
using namespace std ;
bool subset(set<int>&a, set<int>&b)
{
    bool f=1;
    for(auto i :a )
        if(!b.count(i))
            f &=0;
    return f;
}
int main() {
    string s ;
    while (getline(cin,s))
    {
        stringstream gta (s);
        set<int>a,b;
        int tmp;
        while (gta>>tmp)
            a.insert(tmp);
        getline(cin,s);
        stringstream gtb(s);
        while(gtb>>tmp)
            b.insert(tmp);
        if (a==b )
            cout<<"A equals B"<<endl;
        else
        {
            if(subset(a,b))
                cout<<"A is a proper subset of B"<<endl;
            else if(subset(b,a))
                cout<<"B is a proper subset of A"<<endl;
            else
            {
                bool f =1;
                for(auto i : a )
                    if(b.count(i))
                        f &=0;
                if(f)
                    cout<<"A and B are disjoint"<<endl;
                else
                    cout<<"I'm confused!"<<endl;

            }
        }

    }
    return 0;
}
