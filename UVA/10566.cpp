#include <bits/stdc++.h>
using namespace std ;

int main() {
    double x , y ,c ;
    while(cin>>x>>y>>c)
    {
        double l=0  ,r=y ;
        double mid =0 ;
        while(r-l>0.00001) {
            mid = (l + r) / 2;
            double c1 = (sqrt(x * x - mid * mid) * sqrt(y * y - mid * mid)) /
                        (sqrt(x * x - mid * mid) + sqrt(y * y - mid * mid));
            if (c1 > c) l = mid;
            else r = mid;
        }
        printf("%0.3f\n",mid);
    //56.444 493.090 6.169
    }
    return 0;
}
