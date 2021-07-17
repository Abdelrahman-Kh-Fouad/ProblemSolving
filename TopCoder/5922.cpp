#include <bits/stdc++.h>
using namespace std ;
class IntegerSequence {
public:
    int maxSubsequence(vector<int>arr)
    {
        vector<int>pos(arr.size()) , neg(arr.size());
        lis(arr , pos);
        reverse(arr.begin() ,arr.end());
        lis(arr , neg);
        reverse(neg.begin() ,neg.end() );
        int res =0 ;
        for(int i =0 ;i < arr.size() ;i++)
            res = max(res  ,  pos[i]+neg[i]-1  );
        return arr.size()-res;
    }
    void lis(vector<int>&arr,vector<int>&res )
    {
        vector<int>l(arr.size() , INT_MAX);
        for(int i =0 ;i < arr.size() ;i++)
        {
            int ind = lower_bound(l.begin() ,l.end() ,arr[i])-l.begin();
            l[ind]=arr[i];
            res[i]=ind+1;
        }
    }

};
// int main ()
// {
//     IntegerSequence *s =new IntegerSequence();
//     vector<int> arr={1, 4, 6, 5, 2, 1};
//     cout<< s->maxSubsequence(arr)<<endl;
// }
