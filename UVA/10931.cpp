#include <bits//stdc++.h>
using namespace std ;
int main() {
    unsigned int n ;

    while (cin>>n, n!=0)
    {
        bitset<32>tmp(n);
        int len = floor(log2(n))+1;
        string s ="";
        for (int i=len-1 ; i>=0 ;i--)
            s.push_back('0'+(int)tmp.test(i));

        cout<<"The parity of "<<s<<" is "<<tmp.count()<<" (mod 2)."<<endl;
    }
    return 0;
}
